/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkWarpVector.h,v $
  Language:  C++
  Date:      $Date: 1994-05-01 16:16:26 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Class to transform points
//
#ifndef __vlWarpVector_h
#define __vlWarpVector_h

#include "PtS2PtSF.hh"
#include "Trans.hh"

class vlWarpVector : public vlPointSetToPointSetFilter
{
public:
  vlWarpVector() : ScaleFactor(0.0) {};
  ~vlWarpVector() {};
  char *GetClassName() {return "vlWarpVector";};
  void PrintSelf(ostream& os, vlIndent indent);

  vlSetMacro(ScaleFactor,float);
  vlGetMacro(ScaleFactor,float);

protected:
  void Execute();
  float ScaleFactor;
};

#endif


