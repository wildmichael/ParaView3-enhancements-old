/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkAttributeDataToFieldDataFilter.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:29:05 $
  Version:   $Revision: 1.14 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkAttributeDataToFieldDataFilter.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkAttributeDataToFieldDataFilter, "$Revision: 1.14 $");
vtkStandardNewMacro(vtkAttributeDataToFieldDataFilter);

// Instantiate object.
vtkAttributeDataToFieldDataFilter::vtkAttributeDataToFieldDataFilter()
{
  this->PassAttributeData = 1;
}

void vtkAttributeDataToFieldDataFilter::Execute()
{
  vtkDataSet *input = (vtkDataSet *)this->GetInput();
  vtkDataSet *output = (vtkDataSet *)this->GetOutput();
  
  output->CopyStructure( input );
  output->GetPointData()->PassData( input->GetPointData() );
  output->GetCellData()->PassData( input->GetCellData() );

}

void vtkAttributeDataToFieldDataFilter::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);

  os << indent << "Pass Attribute Data: " << (this->PassAttributeData ? "On\n" : "Off\n");
}

