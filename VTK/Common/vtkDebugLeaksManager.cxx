/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkDebugLeaksManager.cxx,v $
  Language:  C++
  Date:      $Date: 2002-06-24 22:15:41 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkDebugLeaksManager.h"
#include "vtkDebugLeaks.h"

vtkDebugLeaksManager::vtkDebugLeaksManager()
{
  if(++vtkDebugLeaksManager::Count == 1)
    {
    vtkDebugLeaks::ClassInitialize();
    }
}

vtkDebugLeaksManager::~vtkDebugLeaksManager()
{
  if(--vtkDebugLeaksManager::Count == 0)
    {
    vtkDebugLeaks::ClassFinalize();
    }
}

// Must NOT be initialized.  Default initialization to zero is
// necessary.
unsigned int vtkDebugLeaksManager::Count;
