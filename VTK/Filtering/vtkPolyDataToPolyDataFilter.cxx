/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPolyDataToPolyDataFilter.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:28:10 $
  Version:   $Revision: 1.13 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPolyDataToPolyDataFilter.h"

vtkCxxRevisionMacro(vtkPolyDataToPolyDataFilter, "$Revision: 1.13 $");

//----------------------------------------------------------------------------
vtkPolyDataToPolyDataFilter::vtkPolyDataToPolyDataFilter() 
{
  this->vtkProcessObject::SetNumberOfInputs(1);
  this->NumberOfRequiredInputs = 1;
}
//----------------------------------------------------------------------------
// Specify the input data or filter.
void vtkPolyDataToPolyDataFilter::SetInput(vtkPolyData *input)
{
  this->vtkProcessObject::SetNthInput(0, input);
}

//----------------------------------------------------------------------------
// Specify the input data or filter.
vtkPolyData *vtkPolyDataToPolyDataFilter::GetInput()
{
  if (this->NumberOfInputs < 1)
    {
    return NULL;
    }
  
  return (vtkPolyData *)(this->Inputs[0]);
}



