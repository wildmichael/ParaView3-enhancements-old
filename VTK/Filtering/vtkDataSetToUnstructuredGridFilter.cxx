/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkDataSetToUnstructuredGridFilter.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:28:04 $
  Version:   $Revision: 1.22 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkDataSetToUnstructuredGridFilter.h"

vtkCxxRevisionMacro(vtkDataSetToUnstructuredGridFilter, "$Revision: 1.22 $");

//----------------------------------------------------------------------------
// Specify the input data or filter.
void vtkDataSetToUnstructuredGridFilter::SetInput(vtkDataSet *input)
{
  this->vtkProcessObject::SetNthInput(0, input);
}

//----------------------------------------------------------------------------
// Specify the input data or filter.
vtkDataSet *vtkDataSetToUnstructuredGridFilter::GetInput()
{
  if (this->NumberOfInputs < 1)
    {
    return NULL;
    }
  
  return (vtkDataSet *)(this->Inputs[0]);
}

