/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkTimeStamp.cxx,v $
  Language:  C++
  Date:      $Date: 1995-06-29 17:57:33 $
  Version:   $Revision: 1.6 $

This file is part of the Visualization Toolkit. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Initialize static member
//
#include "TimeSt.hh"

unsigned long vtkTimeStamp::vtkTime = 0;
