/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkTetra.h,v $
  Language:  C++
  Date:      $Date: 1994-03-08 20:46:33 $
  Version:   $Revision: 1.2 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Computational class for tetras.
//
#ifndef __vlTetra_h
#define __vlTetra_h

#include "Cell.hh"

class vlTetra : public vlCell
{
public:
  vlTetra() {};
  char *GetClassName() {return "vlTetra";};

  float EvaluatePosition(float x[3], int& subId, float pcoords[3]);
  void EvaluateLocation(int& subId, float pcoords[3], float x[3]);

};

#endif


