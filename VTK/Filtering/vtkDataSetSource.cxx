/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkDataSetSource.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:28:02 $
  Version:   $Revision: 1.9 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkDataSetSource.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkDataSetSource, "$Revision: 1.9 $");
vtkStandardNewMacro(vtkDataSetSource);

vtkDataSetSource::vtkDataSetSource()
{

}

//----------------------------------------------------------------------------
vtkDataSet *vtkDataSetSource::GetOutput()
{
  if (this->NumberOfOutputs < 1)
    {
    return NULL;
    }
  
  return (vtkDataSet *)(this->Outputs[0]);
}

//----------------------------------------------------------------------------
void vtkDataSetSource::SetOutput(vtkDataSet *output)
{
  this->vtkSource::SetNthOutput(0, output);
}

