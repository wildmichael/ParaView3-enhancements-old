/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkSphereSource.cxx,v $
  Language:  C++
  Date:      $Date: 1994-02-04 12:44:57 $
  Version:   $Revision: 1.2 $

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Methods for Sphere generator
//
#include <math.h>
#include "SpherSrc.hh"

vlSphereSource::vlSphereSource(int res)
{
  res = (res < 0 ? 0 : res);
  this->Resolution = res;
  this->Radius = 0.5;
}

void vlSphereSource::Execute()
{

}
