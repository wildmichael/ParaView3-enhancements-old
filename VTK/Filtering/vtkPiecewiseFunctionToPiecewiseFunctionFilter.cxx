/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPiecewiseFunctionToPiecewiseFunctionFilter.cxx,v $
  Language:  C++
  Date:      $Date: 2002-02-15 16:19:52 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPiecewiseFunctionToPiecewiseFunctionFilter.h"

vtkCxxRevisionMacro(vtkPiecewiseFunctionToPiecewiseFunctionFilter, "$Revision: 1.1 $");

//----------------------------------------------------------------------------
vtkPiecewiseFunctionToPiecewiseFunctionFilter::vtkPiecewiseFunctionToPiecewiseFunctionFilter() 
{
  this->vtkProcessObject::SetNumberOfInputs(1);
  this->NumberOfRequiredInputs = 1;
}
//----------------------------------------------------------------------------
// Specify the input data or filter.
void vtkPiecewiseFunctionToPiecewiseFunctionFilter::SetInput(vtkPiecewiseFunction *input)
{
  this->vtkProcessObject::SetNthInput(0, input);
}

//----------------------------------------------------------------------------
// Specify the input data or filter.
vtkPiecewiseFunction *vtkPiecewiseFunctionToPiecewiseFunctionFilter::GetInput()
{
  if (this->NumberOfInputs < 1)
    {
    return NULL;
    }
  
  return (vtkPiecewiseFunction *)(this->Inputs[0]);
}
