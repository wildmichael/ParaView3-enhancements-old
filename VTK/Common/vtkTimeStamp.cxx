/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkTimeStamp.cxx,v $
  Language:  C++
  Date:      $Date: 1994-02-04 12:42:29 $
  Version:   $Revision: 1.5 $

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Initialize static member
//
#include "TimeSt.hh"

unsigned long vlTimeStamp::vlTime = 0;
