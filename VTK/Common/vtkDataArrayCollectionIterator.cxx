/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkDataArrayCollectionIterator.cxx,v $
  Language:  C++
  Date:      $Date: 2002-07-11 21:16:23 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkDataArrayCollectionIterator.h"
#include "vtkObjectFactory.h"
#include "vtkDataArray.h"
#include "vtkDataArrayCollection.h"

vtkCxxRevisionMacro(vtkDataArrayCollectionIterator, "$Revision: 1.1 $");
vtkStandardNewMacro(vtkDataArrayCollectionIterator);

//----------------------------------------------------------------------------
vtkDataArrayCollectionIterator::vtkDataArrayCollectionIterator()
{
}

//----------------------------------------------------------------------------
vtkDataArrayCollectionIterator::~vtkDataArrayCollectionIterator()
{
}

//----------------------------------------------------------------------------
void vtkDataArrayCollectionIterator::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}

//----------------------------------------------------------------------------
void vtkDataArrayCollectionIterator::SetCollection(vtkCollection* c)
{
  if(c)
    {
    this->Superclass::SetCollection(vtkDataArrayCollection::SafeDownCast(c));
    if(!this->Collection)
      {
      vtkErrorMacro("vtkDataArrayCollectionIterator cannot traverse a "
                    << c->GetClassName());
      }
    }
  else
    {
    this->Superclass::SetCollection(0);
    }
}

//----------------------------------------------------------------------------
void vtkDataArrayCollectionIterator::SetCollection(vtkDataArrayCollection* c)
{
  this->Superclass::SetCollection(c);
}

//----------------------------------------------------------------------------
vtkDataArray* vtkDataArrayCollectionIterator::GetDataArray()
{
  return static_cast<vtkDataArray*>(this->GetObject());
}
