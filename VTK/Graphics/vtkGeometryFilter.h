/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkGeometryFilter.h,v $
  Language:  C++
  Date:      $Date: 1994-04-05 08:11:12 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Extracts geometry from arbitrary input
//
#ifndef __vlGeometryFilter_h
#define __vlGeometryFilter_h

#include "DS2PolyF.hh"

class vlGeometryFilter : public vlDataSetToPolyFilter
{
public:
  vlGeometryFilter();
  ~vlGeometryFilter() {};
  char *GetClassName() {return "vlGeometryFilter";};
  void PrintSelf(ostream& os, vlIndent indent);

protected:
  void Execute();
};

#endif


