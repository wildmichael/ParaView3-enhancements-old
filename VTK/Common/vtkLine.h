/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkLine.h,v $
  Language:  C++
  Date:      $Date: 1994-02-08 11:46:48 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Create line centered at origin
//
#ifndef __vlLine_h
#define __vlLine_h

#include "Object.hh"
#include "Points.hh"
#include "CellArr.hh"
#include "FNormals.hh"

#define MAX_RESOLUTION MAX_VERTS

class vlLine : public vlObject
{
public:
  vlLine() {};
  char *GetClassName() {return "vlLine";};

  int GenerateNormals(vlPoints *, vlCellArray *, vlFloatNormals *);

};

#endif


