/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkUnstructuredGridVolumeMapper.cxx,v $
  Language:  C++
  Date:      $Date: 2003-11-25 06:06:45 $
  Version:   $Revision: 1.2 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkUnstructuredGridVolumeMapper.h"

#include "vtkUnstructuredGrid.h"
#include "vtkDataSet.h"

vtkCxxRevisionMacro(vtkUnstructuredGridVolumeMapper, "$Revision: 1.2 $");

// Construct a vtkUnstructuredGridVolumeMapper with empty scalar input and clipping off.
vtkUnstructuredGridVolumeMapper::vtkUnstructuredGridVolumeMapper()
{
  this->BlendMode = vtkUnstructuredGridVolumeMapper::COMPOSITE_BLEND;
}

vtkUnstructuredGridVolumeMapper::~vtkUnstructuredGridVolumeMapper()
{  
}

void vtkUnstructuredGridVolumeMapper::SetInput( vtkDataSet *genericInput )
{
  vtkUnstructuredGrid *input = 
    vtkUnstructuredGrid::SafeDownCast( genericInput );
  
  if ( input )
    {
    this->SetInput( input );
    }
  else
    {
    vtkErrorMacro("The SetInput method of this mapper requires vtkImageData as input");
    }
}

void vtkUnstructuredGridVolumeMapper::SetInput( vtkUnstructuredGrid *input )
{
  this->vtkProcessObject::SetNthInput(0, input);
}

vtkUnstructuredGrid *vtkUnstructuredGridVolumeMapper::GetInput()
{
  if (this->NumberOfInputs < 1)
    {
    return NULL;
    }
  return (vtkUnstructuredGrid *)this->Inputs[0];
}


// Print the vtkUnstructuredGridVolumeMapper
void vtkUnstructuredGridVolumeMapper::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
  
  os << indent << "Blend Mode: " << this->BlendMode << endl;
}

