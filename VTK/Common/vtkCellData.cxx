/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkCellData.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:25:13 $
  Version:   $Revision: 1.12 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkCellData.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkCellData, "$Revision: 1.12 $");
vtkStandardNewMacro(vtkCellData);

void vtkCellData::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
