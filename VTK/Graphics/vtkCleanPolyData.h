/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkCleanPolyData.h,v $
  Language:  C++
  Date:      $Date: 1994-05-23 22:26:04 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Merges duplicate points and transforms degenerate topology into 
// appropriate form (for example, triangle into line is two points 
// are merged)
//
#ifndef __vlCleanPolyData_h
#define __vlCleanPolyData_h

#include "P2PF.hh"

class vlCleanPolyData : public vlPolyToPolyFilter
{
public:
  vlCleanPolyData();
  ~vlCleanPolyData();
  char *GetClassName() {return "vlCleanPolyData";};
  void PrintSelf(ostream& os, vlIndent indent);

  vlSetClampMacro(Tolerance,float,0.0,1.0); //% of bounding box
  vlGetMacro(Tolerance,float);

  vlSetObjectMacro(Locator,vlLocator);
  vlGetObjectMacro(Locator,vlLocator);

protected:
  // Usual data generation method
  void Execute();

  float Tolerance;
  vlLocator *Locator;
};

#endif


