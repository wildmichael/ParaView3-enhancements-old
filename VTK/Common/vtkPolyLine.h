/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkPolyLine.h,v $
  Language:  C++
  Date:      $Date: 1994-03-03 20:05:02 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Computational class for polylines.
//
#ifndef __vlPolyLine_h
#define __vlPolyLine_h

#include "Cell.hh"
#include "Points.hh"
#include "CellArr.hh"
#include "FNormals.hh"

#define MAX_RESOLUTION MAX_VERTS

class vlPolyLine : public vlCell
{
public:
  vlPolyLine() {};
  char *GetClassName() {return "vlPolyLine";};

  int GenerateNormals(vlPoints *, vlCellArray *, vlFloatNormals *);

  float DistanceToPoint(float *x);

};

#endif


