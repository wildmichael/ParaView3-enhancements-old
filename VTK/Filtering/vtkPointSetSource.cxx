/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPointSetSource.cxx,v $
  Language:  C++
  Date:      $Date: 2002-07-03 15:59:39 $
  Version:   $Revision: 1.9 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPointSetSource.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkPointSetSource, "$Revision: 1.9 $");

//----------------------------------------------------------------------------
vtkPointSetSource::vtkPointSetSource()
{

}

//----------------------------------------------------------------------------
vtkPointSet *vtkPointSetSource::GetOutput()
{
  if (this->NumberOfOutputs < 1)
    {
    return NULL;
    }
  
  return (vtkPointSet *)(this->Outputs[0]);
}


//----------------------------------------------------------------------------
void vtkPointSetSource::SetOutput(vtkPointSet *output)
{
  this->vtkSource::SetNthOutput(0, output);
}



