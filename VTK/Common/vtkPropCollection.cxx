/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPropCollection.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:26:10 $
  Version:   $Revision: 1.9 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPropCollection.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkPropCollection, "$Revision: 1.9 $");
vtkStandardNewMacro(vtkPropCollection);

int vtkPropCollection::GetNumberOfPaths()
{
  int numPaths=0;
  vtkProp *aProp;

  for ( this->InitTraversal(); (aProp=this->GetNextProp()); )
    {
    numPaths += aProp->GetNumberOfPaths();
    }
  return numPaths;
}
