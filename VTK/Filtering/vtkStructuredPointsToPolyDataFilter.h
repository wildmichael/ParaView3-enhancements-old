/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStructuredPointsToPolyDataFilter.h,v $
  Language:  C++
  Date:      $Date: 1994-07-11 11:51:38 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// StructuredPointsToPolyDataFilter are filters that take 
// StructuredPoints as input and generate PolyData data as output
//
#ifndef __vlStructuredPointsToPolyDataFilter_h
#define __vlStructuredPointsToPolyDataFilter_h

#include "StrPtsF.hh"
#include "PolyData.hh"

class vlStructuredPointsToPolyDataFilter : public vlPolyData, 
                                              public vlStructuredPointsFilter
{
public:
  void Update();
  char *GetClassName() {return "vlDataSetToPolyDataFilter";};
  void PrintSelf(ostream& os, vlIndent indent);
};

#endif


