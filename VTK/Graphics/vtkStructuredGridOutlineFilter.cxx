/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStructuredGridOutlineFilter.cxx,v $
  Language:  C++
  Date:      $Date: 1994-08-05 09:08:42 $
  Version:   $Revision: 1.1 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#include "StrOutlF.hh"

void vlStructuredOutlineFilter::Execute()
{
  vlFloatPoints *newPts;
  vlCellArray *newLines;

  vlDebugMacro(<< "Creating structured outline");
  this->Initialize();

//
// Update selves
//
  this->SetPoints(newPts);
  this->SetLines(newLines);

}
