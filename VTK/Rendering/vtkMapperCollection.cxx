/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkMapperCollection.cxx,v $
  Language:  C++
  Date:      $Date: 2002-08-22 18:39:30 $
  Version:   $Revision: 1.7 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkMapperCollection.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkMapperCollection, "$Revision: 1.7 $");
vtkStandardNewMacro(vtkMapperCollection);

void vtkMapperCollection::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
