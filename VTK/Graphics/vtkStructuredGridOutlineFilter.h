/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkStructuredGridOutlineFilter.h,v $
  Language:  C++
  Date:      $Date: 1995-06-30 16:29:08 $
  Version:   $Revision: 1.5 $

This file is part of the Visualization Toolkit. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vtkStructuredGridOutlineFilter - create wireframe outline for structured grid
// .SECTION Description
// vtkStructuredGridOutlineFilter is a filter that generates a wireframe 
// outline of a structured grid (vtkStructuredGrid). Structured data is 
// topologically a cube, so the outline will have 12 "edges".

#ifndef __vtkStructuredGridOutlineFilter_h
#define __vtkStructuredGridOutlineFilter_h

#include "SG2PolyF.hh"

class vtkStructuredGridOutlineFilter : public vtkStructuredGridToPolyFilter
{
public:
  vtkStructuredGridOutlineFilter() {};
  ~vtkStructuredGridOutlineFilter() {};
  char *GetClassName() {return "vtkStructuredGridOutlineFilter";};

protected:
  void Execute();
};

#endif


