/*=========================================================================

Program:   Visualization Toolkit
Module:    $RCSfile: vtkQtRichTextView.cxx,v $

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*-------------------------------------------------------------------------
  Copyright 2008 Sandia Corporation.
  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
  the U.S. Government retains certain rights in this software.
  -------------------------------------------------------------------------*/

#include "vtkAlgorithm.h"
#include "vtkAlgorithmOutput.h"
#include "vtkAnnotationLink.h"
#include "vtkCommand.h"
#include "vtkConvertSelection.h"
#include "vtkDataObjectToTable.h"
#include "vtkDataRepresentation.h"
#include "vtkIdTypeArray.h"
#include "vtkInformation.h"
#include "vtkObjectFactory.h"
#include "vtkQtRichTextView.h"
#include "vtkSelection.h"
#include "vtkSelectionNode.h"
#include "vtkSelectionSource.h"
#include "vtkSmartPointer.h"
#include "vtkTable.h"
#include "vtkVariantArray.h"

#include <ui_vtkQtRichTextView.h>

#include <QFrame>
#include <QNetworkAccessManager>
#include <QNetworkProxy>
#include <QObject>
#include <QPointer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebFrame>
#include <QWebHistory>
#include <QWebView>
#include <QHttpHeader>
#include <QHttpRequestHeader>

vtkCxxRevisionMacro(vtkQtRichTextView, "$Revision: 1.19 $");
vtkStandardNewMacro(vtkQtRichTextView);

/////////////////////////////////////////////////////////////////////////////
// vtkQtRichTextView::Implementation

class vtkQtRichTextView::Implementation
{
public:
  ~Implementation()
  {
    delete this->Widget;
  }

  // Handles conversion of our input data to a table for display
  vtkSmartPointer<vtkDataObjectToTable> DataObjectToTable;

  // Caches displayed content so we can navigate backwards to it
  vtkUnicodeString Content;

  QPointer<QWidget> Widget;
  Ui::vtkQtRichTextView UI;
};

/////////////////////////////////////////////////////////////////////////////
// vtkQtRichTextView

vtkQtRichTextView::vtkQtRichTextView()
{
  this->ContentColumnName=NULL;
  this->ProxyPort = 0;
  this->ProxyURL = NULL;
  this->SetContentColumnName("html");
  this->Internal = new Implementation();
  this->Internal->DataObjectToTable = vtkSmartPointer<vtkDataObjectToTable>::New();
  this->Internal->DataObjectToTable->SetFieldType(ROW_DATA);

  this->Internal->Widget = new QWidget();
  this->Internal->UI.setupUi(this->Internal->Widget);
  this->Internal->UI.WebView->setHtml("");
  //QNetworkProxy proxy(QNetworkProxy::HttpCachingProxy,"wwwproxy.sandia.gov",80);
  //QNetworkProxy::setApplicationProxy(proxy);

  QObject::connect(this->Internal->UI.BackButton, SIGNAL(clicked()), this, SLOT(onBack()));
  QObject::connect(this->Internal->UI.ZoomIn, SIGNAL(clicked()), this, SLOT(onZoomIn()));
  QObject::connect(this->Internal->UI.ZoomReset, SIGNAL(clicked()), this, SLOT(onZoomReset()));
  QObject::connect(this->Internal->UI.ZoomOut, SIGNAL(clicked()), this, SLOT(onZoomOut()));
  QObject::connect(this->Internal->UI.WebView, SIGNAL(loadProgress(int)), this, SLOT(onLoadProgress(int)));
}

vtkQtRichTextView::~vtkQtRichTextView()
{
  delete this->Internal;
}

void vtkQtRichTextView::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
  os << indent << "ProxyURL : " << (this->ProxyURL ? this->ProxyURL : "(none)") << endl;
  os << indent << "ProxyPort: " << this->ProxyPort << endl;
  os << indent << "ContentColumnName: " << this->ContentColumnName << endl;
}

QWidget* vtkQtRichTextView::GetWidget()
{
  return this->Internal->Widget;
}

void vtkQtRichTextView::SetFieldType(int type)
{
  this->Internal->DataObjectToTable->SetFieldType(type);
  this->Update();
}

int vtkQtRichTextView::GetFieldType()
{
  return this->Internal->DataObjectToTable->GetFieldType();
}

void vtkQtRichTextView::Update()
{

  // Set the proxy (if needed)
  if(this->ProxyURL && this->ProxyPort >=0)
    {
    if(this->ProxyPort > 65535)
      {
      vtkWarningMacro(<<"Proxy port number, "<<this->ProxyPort<<", > 65535 (max for TCP/UDP)");
      }
    QNetworkProxy proxy(QNetworkProxy::HttpCachingProxy, ProxyURL, ProxyPort);
    QNetworkProxy::setApplicationProxy(proxy);
    }
  else
    {
    QNetworkProxy proxy(QNetworkProxy::NoProxy);
    QNetworkProxy::setApplicationProxy(proxy);
    }

  // Make sure the input connection is up to date ...
  vtkDataRepresentation* const representation = this->GetRepresentation();
  if(!representation)
    {
    this->Internal->UI.WebView->setHtml("");
    return;
    }
  representation->Update();

  if(this->Internal->DataObjectToTable->GetTotalNumberOfInputConnections() == 0
      || this->Internal->DataObjectToTable->GetInputConnection(0, 0) != representation->GetInternalOutputPort(0))
    {
    this->Internal->DataObjectToTable->SetInputConnection(0, representation->GetInternalOutputPort(0));
    }
  this->Internal->DataObjectToTable->Update();

  // Get our input table ...
  vtkTable* const table = this->Internal->DataObjectToTable->GetOutput();
  if(!table)
    {
    this->Internal->UI.WebView->setHtml("");
    return;
    }

  // Special-case: if the table is empty, we're done ...
  if(table->GetNumberOfRows() == 0)
    {
    this->Internal->UI.WebView->setHtml("");
    return;
    }

  vtkSelection* s = representation->GetAnnotationLink()->GetCurrentSelection();

  vtkSmartPointer<vtkSelection> selection;
  selection.TakeReference(vtkConvertSelection::ToSelectionType(
    s, table, vtkSelectionNode::INDICES, 0, vtkSelectionNode::ROW));

  if(!selection.GetPointer() || selection->GetNumberOfNodes() == 0)
    {
    this->Internal->UI.WebView->setHtml("");
    return;
    }

  vtkIdTypeArray* selectedRows = vtkIdTypeArray::SafeDownCast(selection->GetNode(0)->GetSelectionList());
  if(selectedRows->GetNumberOfTuples() == 0)
    {
    this->Internal->UI.WebView->setHtml("");
    return;
    }

  vtkIdType row = selectedRows->GetValue(0);

  this->Internal->UI.WebView->history()->clear(); // Workaround for a quirk in QWebHistory

  this->Internal->Content = table->GetValueByName(row, this->ContentColumnName).ToUnicodeString();
  //cerr << this->Internal->Content << endl;

  this->Internal->UI.WebView->setContent(this->Internal->Content.utf8_str());
}

void vtkQtRichTextView::onBack()
{
  // This logic is a workaround for a quirk in QWebHistory
  if(this->Internal->UI.WebView->history()->currentItemIndex() <= 1)
    {
    this->Internal->UI.WebView->setHtml(QString::fromUtf8(this->Internal->Content.utf8_str()));
    this->Internal->UI.WebView->history()->clear();
    }
  else
    {
    this->Internal->UI.WebView->back();
    }
}

void vtkQtRichTextView::onZoomIn()
{
  this->Internal->UI.WebView->setTextSizeMultiplier(this->Internal->UI.WebView->textSizeMultiplier() * 1.1);
}

void vtkQtRichTextView::onZoomReset()
{
  this->Internal->UI.WebView->setTextSizeMultiplier(1.0);
}

void vtkQtRichTextView::onZoomOut()
{
  this->Internal->UI.WebView->setTextSizeMultiplier(this->Internal->UI.WebView->textSizeMultiplier() * (1.0 / 1.1));
}

void vtkQtRichTextView::onLoadProgress(int progress)
{
  ViewProgressEventCallData callData("Web Page Loading", progress/100.0);
  this->InvokeEvent(vtkCommand::ViewProgressEvent, &callData);
}
