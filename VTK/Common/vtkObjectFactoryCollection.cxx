/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkObjectFactoryCollection.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:25:48 $
  Version:   $Revision: 1.2 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkObjectFactoryCollection.h"

vtkCxxRevisionMacro(vtkObjectFactoryCollection, "$Revision: 1.2 $");

vtkObjectFactoryCollection* vtkObjectFactoryCollection::New() 
{
#ifdef VTK_DEBUG_LEAKS
  vtkDebugLeaks::ConstructClass("vtkObjectFactoryCollection");
#endif    
  return new vtkObjectFactoryCollection;
}

