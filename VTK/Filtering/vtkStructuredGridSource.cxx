/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStructuredGridSource.cxx,v $
  Language:  C++
  Date:      $Date: 1994-11-06 19:40:20 $
  Version:   $Revision: 1.2 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#include "SGridSrc.hh"

void vlStructuredGridSource::Modified()
{
  this->vlStructuredGrid::Modified();
  this->vlSource::_Modified();
}

unsigned long int vlStructuredGridSource::GetMTime()
{
  unsigned long dtime = this->vlStructuredGrid::GetMTime();
  unsigned long ftime = this->vlSource::_GetMTime();
  return (dtime > ftime ? dtime : ftime);
}

void vlStructuredGridSource::Update()
{
  this->UpdateFilter();
}

void vlStructuredGridSource::PrintSelf(ostream& os, vlIndent indent)
{
  vlStructuredGrid::PrintSelf(os,indent);
  vlSource::_PrintSelf(os,indent);
}
