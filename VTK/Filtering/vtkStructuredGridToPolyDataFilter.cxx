/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkStructuredGridToPolyDataFilter.cxx,v $
  Language:  C++
  Date:      $Date: 2002-09-03 20:33:58 $
  Version:   $Revision: 1.12 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkStructuredGridToPolyDataFilter.h"

#include "vtkStructuredGrid.h"

vtkCxxRevisionMacro(vtkStructuredGridToPolyDataFilter, "$Revision: 1.12 $");

//----------------------------------------------------------------------------
// Specify the input data or filter.
void vtkStructuredGridToPolyDataFilter::SetInput(vtkStructuredGrid *input)
{
  this->vtkProcessObject::SetNthInput(0, input);
}

//----------------------------------------------------------------------------
// Specify the input data or filter.
vtkStructuredGrid *vtkStructuredGridToPolyDataFilter::GetInput()
{
  if (this->NumberOfInputs < 1)
    {
    return NULL;
    }
  
  return (vtkStructuredGrid *)(this->Inputs[0]);
}



