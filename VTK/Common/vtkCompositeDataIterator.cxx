/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkCompositeDataIterator.cxx,v $
  Language:  C++
  Date:      $Date: 2003-12-11 15:47:36 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkCompositeDataIterator.h"

vtkCxxRevisionMacro(vtkCompositeDataIterator, "$Revision: 1.1 $");

//----------------------------------------------------------------------------
vtkCompositeDataIterator::vtkCompositeDataIterator()
{
}

//----------------------------------------------------------------------------
vtkCompositeDataIterator::~vtkCompositeDataIterator()
{
}

//----------------------------------------------------------------------------
void vtkCompositeDataIterator::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}

