/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStructuredPointsSource.h,v $
  Language:  C++
  Date:      $Date: 1994-07-13 21:42:37 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/

// .NAME vlStructuredPointsSource - generate vlStructuredPoints data
// .SECTION Description
// vlStructuredPointsSource is an abstract class whose subclasses
// generate vlStructuredPoints data.

#ifndef __vlStructuredPointsSource_h
#define __vlStructuredPointsSource_h

#include "Source.hh"
#include "StrPts.hh"

class vlStructuredPointsSource : public vlSource, public vlStructuredPoints
{
public:
  char *GetClassName() {return "vlStructuredPointSource";};
  void PrintSelf(ostream& os, vlIndent indent);
  void Update();
};

#endif


