/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkRibbonFilter.h,v $
  Language:  C++
  Date:      $Date: 1994-06-06 16:16:57 $
  Version:   $Revision: 1.2 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Class creates oriented ribbons from lines of PolyData
//
#ifndef __vlRibbonFilter_h
#define __vlRibbonFilter_h

#include "P2PF.hh"

class vlRibbonFilter : public vlPolyToPolyFilter 
{
public:
  vlRibbonFilter();
  ~vlRibbonFilter() {};
  char *GetClassName() {return "vlRibbonFilter";};
  void PrintSelf(ostream& os, vlIndent indent);

  vlSetClampMacro(Radius,float,0,LARGE_FLOAT);
  vlGetMacro(Radius,float);

  vlSetClampMacro(Angle,float,0,360);
  vlGetMacro(Angle,float);

protected:
  void Execute();
  float Radius;
  float Angle;
};

#endif


