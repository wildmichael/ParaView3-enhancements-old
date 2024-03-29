/*
* Copyright (c) 2007, Sandia Corporation
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the Sandia Corporation nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Sandia Corporation ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Sandia Corporation BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "ClientGeoView.h"

#include <QVTKWidget.h>
#include <vtkAnnotationLink.h>
#include <vtkCommand.h>
#include <vtkDataObject.h>
#include <vtkDataObjectTypes.h>
#include "vtkEventQtSlotConnect.h"
#include <vtkGeoAlignedImageRepresentation.h>
#include <vtkGeoAlignedImageSource.h>
#include <vtkGeoCamera.h>
#include <vtkGeoFileImageSource.h>
#include <vtkGeoGlobeSource.h>
#include <vtkGeoInteractorStyle.h>
#include <vtkGeoMath.h>
#include <vtkGeometryFilter.h>
#include <vtkGeoSampleArcs.h>
#include <vtkGeoTerrain.h>
#include <vtkGeoView.h>
#include <vtkGraph.h>
#include <vtkJPEGReader.h>
#include <vtkMultiBlockDataSet.h>
//#include <vtkOGRReader.h>
#include <vtkPNGReader.h>
#include <vtkPointSet.h>
#include <vtkPVDataInformation.h>
#include <vtkRenderedGraphRepresentation.h>
#include <vtkRenderedSurfaceRepresentation.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSelection.h>
#include <vtkSelectionNode.h>
#include <vtkSMIdTypeVectorProperty.h>
#include <vtkSMProxyManager.h>
#include <vtkSMSelectionDeliveryRepresentationProxy.h>
#include <vtkSMStringVectorProperty.h>
#include <vtkSMSourceProxy.h>
#include <vtkSmartPointer.h>
#include <vtkTextProperty.h>
#include <vtkTimerLog.h>
#include <vtkTable.h>
#include <vtkViewTheme.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>

#include <pqApplicationCore.h>
#include <pqDataRepresentation.h>
#include <pqFilesystem.h>
#include <pqPropertyHelper.h>
#include <pqOutputPort.h>
#include <pqPipelineSource.h>
#include <pqRepresentation.h>
#include <pqSelectionManager.h>
#include <pqServer.h>

#include <QVBoxLayout>

#include <vtksys/stl/map>

#include "ClientGeoViewConfig.h"
#include "vtkPQConfig.h" // For PARAVIEW_DATA_ROOT

////////////////////////////////////////////////////////////////////////////////////
// ClientGeoView::command

class ClientGeoView::command : public vtkCommand
{
public:
  command(ClientGeoView& view) : Target(view) { }
  virtual void Execute(vtkObject*, unsigned long, void*)
  {
    Target.selectionChanged();
  }
  ClientGeoView& Target;
};

////////////////////////////////////////////////////////////////////////////////////
// ClientGeoView::implementation

class ClientGeoView::implementation
{
public:
  implementation() :
    Widget(new QVTKWidget())
  {
    new QVBoxLayout(this->Widget);

    this->View = vtkSmartPointer<vtkGeoView>::New();
    this->Widget->SetRenderWindow(this->View->GetRenderWindow());

    this->Theme.TakeReference(vtkViewTheme::CreateMellowTheme());

    this->VTKConnect = vtkSmartPointer<vtkEventQtSlotConnect>::New();
    this->ImageRepresentation = 0;
    this->Terrain = 0;
  }

  ~implementation()
  {
    delete this->Widget;
    if (this->ImageRepresentation)
      {
      this->ImageRepresentation->GetSource()->ShutDown();
      this->ImageRepresentation->Delete();
      }
    if (this->Terrain)
      {
      this->Terrain->GetSource()->ShutDown();
      this->Terrain->Delete();
      }
  }

  QVTKWidget* const Widget;
  vtkSmartPointer<vtkGeoView> View;
  vtkSmartPointer<vtkViewTheme> Theme;
  vtkSmartPointer<vtkEventQtSlotConnect> VTKConnect;
  vtkGeoAlignedImageRepresentation* ImageRepresentation;
  vtkGeoTerrain* Terrain;

  typedef vtksys_stl::map<pqRepresentation*, vtkSmartPointer<vtkRenderedGraphRepresentation> >
    RepresentationsT;
  RepresentationsT Representations;
};

////////////////////////////////////////////////////////////////////////////////////
// ClientGeoView

ClientGeoView::ClientGeoView(
  const QString& viewmoduletype, 
  const QString& group, 
  const QString& name, 
  vtkSMViewProxy* viewmodule, 
  pqServer* server, 
  QObject* p) :
  pqView(viewmoduletype, group, name, viewmodule, server, p),
  Implementation(new implementation()),
  Command(new command(*this))
{
  // We need to know when the visibilty of any pqrepresentation changes, so that
  // we can update corresponding vtk representations' state.
  this->connect(this, SIGNAL(representationVisibilityChanged(pqRepresentation*, bool)),
    this, SLOT(onRepresentationVisibilityChanged(pqRepresentation*, bool)));
  this->connect(this, SIGNAL(representationRemoved(pqRepresentation*)),
    SLOT(onRepresentationRemoved(pqRepresentation*)));
  this->connect(pqApplicationCore::instance(), SIGNAL(stateLoaded()),
    SLOT(onStateLoaded()));

  // We connect to endRender() to trigger the vtkView update.
  this->connect(this, SIGNAL(endRender()), this, SLOT(renderGeoViewInternal()));

  vtkGeoInteractorStyle *interactorStyle = this->Implementation->View->GetGeoInteractorStyle();
  this->Implementation->VTKConnect->Connect(interactorStyle,
    vtkCommand::EndInteractionEvent, this, SLOT(synchronizeCameraProperties()));
  // Listen to all views that may fire progress events during updating.
  this->Implementation->VTKConnect->Connect(
    this->Implementation->View, vtkCommand::ViewProgressEvent,
    this, SLOT(onViewProgressEvent(vtkObject*, unsigned long, void*, void*)));

  emit this->beginProgress();

  // Add default terrain
  vtkSmartPointer<vtkGeoGlobeSource> terrainSource =
    vtkSmartPointer<vtkGeoGlobeSource>::New();
  terrainSource->Initialize();
  this->Implementation->Terrain = vtkGeoTerrain::New();
  this->Implementation->Terrain->SetSource(terrainSource);
  this->Implementation->View->SetTerrain(this->Implementation->Terrain);
  this->Implementation->ImageRepresentation =
    vtkGeoAlignedImageRepresentation::New();

  vtkStdString tileDatabase(CLIENT_GEO_VIEW_TILE_PATH);
  if (tileDatabase.length() == 0)
    {
    // Load default image.
    vtkPNGReader* const reader = vtkPNGReader::New();
    if(pqFilesystem::shareDirectory().exists("NE2_ps_bath.png"))
      {
      reader->SetFileName(pqFilesystem::shareDirectory().filePath("NE2_ps_bath.png").toAscii().data());
      }
    else
      {
      reader->SetFileName(PARAVIEW_DATA_ROOT "/Data/NE2_ps_bath.png");
      }

    this->Implementation->VTKConnect->Connect(
      reader,  vtkCommand::ProgressEvent, this,
      SLOT(onViewProgressEvent(vtkObject*, unsigned long, void*, void*)));
    reader->Update();
    this->Implementation->VTKConnect->Disconnect(reader);
    vtkImageData* image = reader->GetOutput();
    vtkSmartPointer<vtkGeoAlignedImageSource> imageSource =
      vtkSmartPointer<vtkGeoAlignedImageSource>::New();
    imageSource->SetImage(image);
    imageSource->Initialize();
    this->Implementation->ImageRepresentation->SetSource(imageSource);
    reader->Delete();
    }
  else
    {
    vtkSmartPointer<vtkGeoFileImageSource> imageSource =
      vtkSmartPointer<vtkGeoFileImageSource>::New();
    imageSource->SetPath(tileDatabase.c_str());
    imageSource->Initialize();
    this->Implementation->ImageRepresentation->SetSource(imageSource);
    }

  // Add image representation
  this->Implementation->View->AddRepresentation(
    this->Implementation->ImageRepresentation);

  // Load political boundaries
  vtkRenderedSurfaceRepresentation* const lineRep = vtkRenderedSurfaceRepresentation::New();
  vtkXMLPolyDataReader* const pbReader = vtkXMLPolyDataReader::New();
  
  if(pqFilesystem::shareDirectory().exists("political.vtp"))
    {
    pbReader->SetFileName(pqFilesystem::shareDirectory().filePath("political.vtp").toAscii().data());
    }
  else
    {
    pbReader->SetFileName(PARAVIEW_DATA_ROOT "/Data/political.vtp");
    }

  // Sample and expand political boundaries so they show up ok
  // on the globe.
  vtkSmartPointer<vtkGeoSampleArcs> sampleArcs =
    vtkSmartPointer<vtkGeoSampleArcs>::New();
  sampleArcs->SetInputConnection(pbReader->GetOutputPort());
  sampleArcs->SetInputCoordinateSystemToSpherical();
  sampleArcs->SetOutputCoordinateSystemToSpherical();
  sampleArcs->SetGlobeRadius(vtkGeoMath::EarthRadiusMeters()*1.0001);
  
  // Create representation
  lineRep->SetInputConnection(sampleArcs->GetOutputPort());
  lineRep->SelectableOff();
  this->Implementation->View->AddRepresentation(lineRep);

  // Set mellow theme
  vtkSmartPointer<vtkViewTheme> theme;
  theme.TakeReference(vtkViewTheme::CreateMellowTheme());
  this->Implementation->View->ApplyViewTheme(theme);
  theme->SetLineWidth(1);
  theme->SetCellColor(0.0, 0.0, 0.0);
  theme->SetCellOpacity(0.2);
  this->Implementation->View->ApplyViewTheme(theme);

  // This update is needed, since we just added an internal representation to
  // the view. Note that this is happening in  the constructor, so it's called
  // before any of the external representations are added. Consequently, this is not
  // triggering any external pipeline updates and hence is totally safe.
  //this->Implementation->View->Update();
  this->Implementation->View->ResetCameraClippingRange();
  this->Implementation->View->Render();
  lineRep->Delete();
  pbReader->Delete();

  // Listen for the selection changed event
  this->Implementation->View->AddObserver(
    vtkCommand::SelectionChangedEvent, this->Command);

  emit this->endProgress();
}

ClientGeoView::~ClientGeoView()
{
  delete this->Implementation;
  this->Command->Delete();
}

void ClientGeoView::selectionChanged()
{
  ClientGeoView::implementation::RepresentationsT::iterator it, itEnd;
  it = this->Implementation->Representations.begin();
  itEnd = this->Implementation->Representations.end();
  for(; it != itEnd; ++it)
    {
    pqRepresentation* const representation = it->first;
    if(!representation->isVisible())
      {
      continue;
      }
    vtkRenderedGraphRepresentation* const rep = it->second;

    // Get the representaion's source
    pqDataRepresentation* pqRepr =
      qobject_cast<pqDataRepresentation*>(representation);
    pqOutputPort* opPort = pqRepr->getOutputPortFromInput();
    vtkSMSourceProxy* repSource = vtkSMSourceProxy::SafeDownCast(
      opPort->getSource()->getProxy());

    // Fill the selection source with the selection from the view
    vtkSelection* sel = rep->GetAnnotationLink()->GetCurrentSelection();
    vtkSMSourceProxy* selectionSource =
      pqSelectionManager::createSelectionSource(sel, repSource->GetConnectionID());

    // Set the selection on the representation's source
    repSource->SetSelectionInput(opPort->getPortNumber(),
      selectionSource, 0);
    selectionSource->Delete();

    // Mark the annotation link as modified so it will be updated
    if (this->getAnnotationLink())
      {
      this->getAnnotationLink()->MarkModified(0);
      }
    }
}

QWidget* ClientGeoView::getWidget()
{
  return this->Implementation->Widget;
}

bool ClientGeoView::canDisplay(pqOutputPort* output_port) const
{
  if(!output_port)
    return false;

  pqPipelineSource* const source = output_port->getSource();
  if(!source)
    return false;

  if(this->getServer()->GetConnectionID() != source->getServer()->GetConnectionID())
    return false;

  vtkSMSourceProxy* source_proxy =
    vtkSMSourceProxy::SafeDownCast(source->getProxy());
  if (!source_proxy ||
     source_proxy->GetOutputPortsCreated() == 0)
    {
    return false;
    }

  const char* name = output_port->getDataClassName();
  int type = vtkDataObjectTypes::GetTypeIdFromClassName(name);
  switch(type)
    {
    case VTK_DIRECTED_ACYCLIC_GRAPH:
    case VTK_DIRECTED_GRAPH:
    case VTK_GRAPH:
    case VTK_TREE:
    case VTK_UNDIRECTED_GRAPH:
      return true;
    }

  return false;
}

bool ClientGeoView::saveImage(int, int, const QString& )
{
  return false;
}

vtkImageData* ClientGeoView::captureImage(int)
{
  return 0;
}

void ClientGeoView::onRepresentationVisibilityChanged(pqRepresentation* pqrep, bool visible)
{
  // Don't call any updates on anything -- neither the view, nor the
  // representation. ParaView will handle that.
  ClientGeoView::implementation::RepresentationsT::iterator iter =
    this->Implementation->Representations.find(pqrep);
  if (iter == this->Implementation->Representations.end())
    {
    // The pqrep has not corresponding vtkrep. This can happen when a new pqrep
    // is added to the view. We create a new vtkrep for it.
    vtkSMClientDeliveryRepresentationProxy* const proxy = 
      vtkSMClientDeliveryRepresentationProxy::SafeDownCast(
        pqrep->getProxy());
    if (!proxy || !proxy->GetOutputPort())
      {
      // sanity check. Don't see how this can really happen.
      return;
      }

    vtkRenderedGraphRepresentation* vtkrep = vtkRenderedGraphRepresentation::New();
    vtkrep->SetSelectionType(vtkSelectionNode::PEDIGREEIDS);
    vtkrep->SetInputConnection(proxy->GetOutputPort());
    vtkrep->SetEdgeLayoutStrategyToGeo();
    // If we have an associated annotation link proxy, set the client side
    // object as the annotation link on the representation.
    if (this->getAnnotationLink())
      {
      vtkAnnotationLink* link = static_cast<vtkAnnotationLink*>(this->getAnnotationLink()->GetClientSideObject());
      vtkrep->SetAnnotationLink(link);
      }
    this->Implementation->Representations[pqrep] = vtkrep;
    vtkrep->Delete();
    iter = this->Implementation->Representations.find(pqrep);
    }

  if (visible)
    {
    this->Implementation->View->AddRepresentation(iter->second);
    }
  else
    {
    this->Implementation->View->RemoveRepresentation(iter->second);
    }
}

void ClientGeoView::onRepresentationRemoved(pqRepresentation* representation)
{
  ClientGeoView::implementation::RepresentationsT::iterator iter = 
    this->Implementation->Representations.find(representation);
  if (iter != this->Implementation->Representations.end())
    {
    this->Implementation->View->RemoveRepresentation(iter->second);
    this->Implementation->Representations.erase(iter);
    }
}

void ClientGeoView::renderGeoViewInternal()
{
  ClientGeoView::implementation::RepresentationsT::const_iterator it, itEnd;
  it = this->Implementation->Representations.begin();
  itEnd = this->Implementation->Representations.end();
  for(; it != itEnd; ++it)
    {
    pqRepresentation* const representation = it->first;
    vtkRenderedGraphRepresentation* const rep = it->second;
    vtkSMSelectionDeliveryRepresentationProxy* const proxy = 
      vtkSMSelectionDeliveryRepresentationProxy::SafeDownCast(
        representation->getProxy());

    // Update the selection.
    // Only use the source proxy's selection if we're not using vtkAnnotationLink directly
    if(!this->getAnnotationLink())
      {
      proxy->GetSelectionRepresentation()->Update();
      vtkSelection* sel = vtkSelection::SafeDownCast(
        proxy->GetSelectionRepresentation()->GetOutput());
      rep->GetAnnotationLink()->SetCurrentSelection(sel);
      }

    // Update the current domain map.
    int useDomainMap = vtkSMPropertyHelper(proxy, "UseDomainMap").GetAsInt();
    rep->GetAnnotationLink()->RemoveAllDomainMaps();
    if (useDomainMap)
      {
      vtkSMSourceProxy* domainMap = 0;
      if (vtkSMPropertyHelper(proxy, "DomainMap").GetNumberOfElements() > 0)
        {
        domainMap = vtkSMSourceProxy::SafeDownCast(
          vtkSMPropertyHelper(proxy, "DomainMap").GetAsProxy());
        }
      if (domainMap)
        {
        vtkSMProxyManager* pm = vtkSMProxyManager::GetProxyManager();
        vtkSMClientDeliveryRepresentationProxy* delivery =
          vtkSMClientDeliveryRepresentationProxy::SafeDownCast(
            pm->NewProxy("representations", "ClientDeliveryRepresentation"));
        delivery->SetConnectionID(domainMap->GetConnectionID());
        delivery->AddInput(domainMap, "AddInput");
        delivery->Update();
        vtkTable* output = vtkTable::SafeDownCast(delivery->GetOutput());
        if (output)
          {
          rep->GetAnnotationLink()->AddDomainMap(output);
          }
        }
      }

    vtkStdString latArr = pqPropertyHelper(proxy, "LatitudeArrayName").GetAsString().toStdString();
    vtkStdString lonArr = pqPropertyHelper(proxy, "LongitudeArrayName").GetAsString().toStdString();
    rep->SetLayoutStrategyToAssignCoordinates(lonArr, latArr);
    double explode = vtkSMPropertyHelper(proxy, "ExplodeFactor").GetAsDouble();
    rep->SetEdgeLayoutStrategyToGeo(explode);
    bool vertexLabelVis = vtkSMPropertyHelper(proxy, "VertexLabelVisibility").GetAsInt();
    rep->SetVertexLabelVisibility(vertexLabelVis);
    if (vertexLabelVis)
      {
      vtkStdString vertexLabelArr = pqPropertyHelper(proxy, "VertexLabelArrayName").GetAsString().toStdString();
      rep->SetVertexLabelArrayName(vertexLabelArr);
      }

    rep->GetVertexLabelTextProperty()->SetFontSize(
      vtkSMPropertyHelper(proxy, "VertexLabelFontSize").GetAsInt());

    this->Implementation->Theme->SetPointSize(
      vtkSMPropertyHelper(proxy, "VertexSize").GetAsDouble());

    this->Implementation->Theme->SetPointOpacity(
      vtkSMPropertyHelper(proxy, "VertexOpacity").GetAsDouble());

    if(vtkSMPropertyHelper(proxy, "VertexColorByArray").GetAsInt())
      {
      rep->SetColorVerticesByArray(true);

      rep->SetVertexColorArrayName(
        vtkSMPropertyHelper(proxy, "VertexColorArray").GetAsString());
      }
    else
      {
      rep->SetColorVerticesByArray(false);

      this->Implementation->Theme->SetPointColor(
        vtkSMPropertyHelper(proxy, "VertexColor").GetAsDouble(0),
        vtkSMPropertyHelper(proxy, "VertexColor").GetAsDouble(1),
        vtkSMPropertyHelper(proxy, "VertexColor").GetAsDouble(2));
      }

    rep->SetEdgeLabelVisibility(
      vtkSMPropertyHelper(proxy, "EdgeLabels").GetAsInt());

    rep->SetEdgeLabelArrayName(
      vtkSMPropertyHelper(proxy, "EdgeLabelArray").GetAsString());

    rep->GetEdgeLabelTextProperty()->SetFontSize(
      vtkSMPropertyHelper(proxy, "EdgeLabelFontSize").GetAsInt());

    this->Implementation->Theme->SetLineWidth(
      vtkSMPropertyHelper(proxy, "EdgeWidth").GetAsDouble());

    this->Implementation->Theme->SetCellOpacity(
      vtkSMPropertyHelper(proxy, "EdgeOpacity").GetAsDouble());

    if(vtkSMPropertyHelper(proxy, "EdgeColorByArray").GetAsInt())
      {
      rep->SetColorEdgesByArray(true);

      rep->SetEdgeColorArrayName(
        vtkSMPropertyHelper(proxy, "EdgeColorArray").GetAsString());
      }
    else
      {
      rep->SetColorEdgesByArray(false);

      this->Implementation->Theme->SetCellColor(
        vtkSMPropertyHelper(proxy, "EdgeColor").GetAsDouble(0),
        vtkSMPropertyHelper(proxy, "EdgeColor").GetAsDouble(1),
        vtkSMPropertyHelper(proxy, "EdgeColor").GetAsDouble(2));
      }

    rep->ApplyViewTheme(this->Implementation->Theme);
    }

  emit this->beginProgress();
  this->Implementation->View->Render();
  emit this->endProgress();
}

void ClientGeoView::synchronizeCameraProperties()
{
  vtkGeoCamera *geoCamera = this->Implementation->View->GetGeoInteractorStyle()->GetGeoCamera();
  double camLon = geoCamera->GetLongitude();
  double camLat = geoCamera->GetLatitude();
  double camDistance = geoCamera->GetDistance();
  double camTilt = geoCamera->GetTilt();
  double camHeading = geoCamera->GetHeading();

  vtkSMProxy *viewProxy = this->getProxy();
  vtkSMPropertyHelper(viewProxy,"CameraLongitude").Set(camLon);
  vtkSMPropertyHelper(viewProxy,"CameraLatitude").Set(camLat);
  vtkSMPropertyHelper(viewProxy,"CameraTilt").Set(camTilt);
  vtkSMPropertyHelper(viewProxy,"CameraHeading").Set(camHeading);
  vtkSMPropertyHelper(viewProxy,"CameraDistance").Set(camDistance);
}

void ClientGeoView::onStateLoaded()
{
  vtkSMProxy *viewProxy = this->getProxy();
  double camLon = vtkSMPropertyHelper(viewProxy,"CameraLongitude").GetAsDouble();
  double camLat = vtkSMPropertyHelper(viewProxy,"CameraLatitude").GetAsDouble();
  double camTilt = vtkSMPropertyHelper(viewProxy,"CameraTilt").GetAsDouble();
  double camHeading = vtkSMPropertyHelper(viewProxy,"CameraHeading").GetAsDouble();
  double camDistance = vtkSMPropertyHelper(viewProxy,"CameraDistance").GetAsDouble();

  vtkGeoInteractorStyle *style = this->Implementation->View->GetGeoInteractorStyle();
  vtkGeoCamera *geoCamera = style->GetGeoCamera();
  geoCamera->SetLongitude(camLon);
  geoCamera->SetLatitude(camLat);
  geoCamera->SetDistance(camDistance);
  geoCamera->SetTilt(camTilt);
  geoCamera->SetHeading(camHeading);
  this->Implementation->View->ResetCameraClippingRange();
}

void ClientGeoView::onViewProgressEvent(vtkObject* obj,
  unsigned long vtk_event, void*, void* call_data)
{
  if (vtk_event == vtkCommand::ViewProgressEvent)
    {
    const vtkView::ViewProgressEventCallData* data = 
      reinterpret_cast<const vtkView::ViewProgressEventCallData*>(call_data);

    emit this->progress(QString(data->GetProgressMessage()), 
      static_cast<int>(data->GetProgress()*100.0));
    }
  else if (vtk_event == vtkCommand::ProgressEvent)
    {
    emit this->progress(obj->GetClassName(), 
      static_cast<int>((*reinterpret_cast<double*>(call_data))*100.0));
    }
}
