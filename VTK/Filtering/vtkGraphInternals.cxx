/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkGraphInternals.cxx,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*----------------------------------------------------------------------------
 Copyright (c) Sandia Corporation
 See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.
----------------------------------------------------------------------------*/
#include "vtkGraphInternals.h"

#include "vtkDistributedGraphHelper.h"
#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkGraphInternals);
vtkCxxRevisionMacro(vtkGraphInternals, "$Revision: 1.2 $");

//----------------------------------------------------------------------------
vtkGraphInternals::vtkGraphInternals()
{ 
  this->NumberOfEdges = 0; 
  this->DistributedHelper = 0; 
}

//----------------------------------------------------------------------------
vtkGraphInternals::~vtkGraphInternals()
{
  if (this->DistributedHelper)
    this->DistributedHelper->Delete();
}