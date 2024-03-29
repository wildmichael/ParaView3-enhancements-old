/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkInteractorStyleTreeMapHover.h,v $

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
// .NAME vtkInteractorStyleTreeMapHover - An interactor style for a tree map view
//
// .SECTION Description
// The vtkInteractorStyleTreeMapHover specifically works with pipelines
// that create a tree map.  Such pipelines will have a vtkTreeMapLayout
// filter and a vtkTreeMapToPolyData filter, both of which must be passed
// to this interactor style for it to function correctly.
// This interactor style allows only 2D panning and zooming, and additionally
// provides a balloon containing the name of the vertex hovered over,
// and allows the user to highlight a vertex by clicking on it.

#ifndef __vtkInteractorStyleTreeMapHover_h
#define __vtkInteractorStyleTreeMapHover_h

#include "vtkInteractorStyleImage.h"

class vtkBalloonRepresentation;
class vtkPoints;
class vtkRenderer;
class vtkTree;
class vtkTreeMapLayout;
class vtkTreeMapToPolyData;
class vtkWorldPointPicker;

class VTK_VIEWS_EXPORT vtkInteractorStyleTreeMapHover : public vtkInteractorStyleImage
{
public:
  static vtkInteractorStyleTreeMapHover* New();
  vtkTypeRevisionMacro(vtkInteractorStyleTreeMapHover,vtkInteractorStyleImage);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Must be set to the vtkTreeMapLayout used to compute the bounds of each vertex
  // for the tree map.
  void SetLayout(vtkTreeMapLayout* layout);
  vtkGetObjectMacro(Layout, vtkTreeMapLayout);

  // Description:
  // Must be set to the vtkTreeMapToPolyData used to convert the tree map
  // into polydata.
  void SetTreeMapToPolyData(vtkTreeMapToPolyData* filter);
  vtkGetObjectMacro(TreeMapToPolyData, vtkTreeMapToPolyData);

  // Description:
  // The name of the field to use when displaying text in the hover balloon.
  vtkSetStringMacro(LabelField);
  vtkGetStringMacro(LabelField);
  
  // Description:
  // Overridden from vtkInteractorStyleImage to provide the desired
  // interaction behavior.
  void OnMouseMove();
  void OnLeftButtonUp();
  
  // Description:
  // Highlights a specific vertex.
  void HighLightItem(vtkIdType id);
  void HighLightCurrentSelectedItem();

  virtual void SetInteractor(vtkRenderWindowInteractor *rwi);

  // Description:
  // Set the color used to highlight the hovered vertex.
  void SetHighLightColor(double r, double g, double b);

  // Description:
  // Set the color used to highlight the selected vertex.
  void SetSelectionLightColor(double r, double g, double b);

  // Description:
  // The width of the line around the hovered vertex.
  void SetHighLightWidth(double lw);
  double GetHighLightWidth();

  // Description:
  // The width of the line around the selected vertex.
  void SetSelectionWidth(double lw);
  double GetSelectionWidth();

protected:
  vtkInteractorStyleTreeMapHover();
  ~vtkInteractorStyleTreeMapHover();

private:
  vtkInteractorStyleTreeMapHover(const vtkInteractorStyleTreeMapHover&); // Not implemented
  void operator=(const vtkInteractorStyleTreeMapHover&); // Not implemented

  // These methods are used internally
  vtkIdType GetTreeMapIdAtPos(int x, int y);
  void GetBoundingBoxForTreeMapItem(vtkIdType id, float *binfo);
  
  vtkWorldPointPicker* Picker;
  vtkBalloonRepresentation* Balloon;
  vtkActor *HighlightActor;
  vtkActor *SelectionActor;
  vtkPoints *HighlightPoints;
  vtkPoints *SelectionPoints;
  vtkTreeMapLayout* Layout;
  vtkTreeMapToPolyData* TreeMapToPolyData;
  char *LabelField;
  vtkIdType CurrentSelectedId;
};

#endif
