/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkDummyController.cxx,v $
  Language:  C++
  Date:      $Date: 2002-06-27 19:45:21 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkDummyController.h"
#include "vtkObjectFactory.h"

vtkCxxRevisionMacro(vtkDummyController, "$Revision: 1.1 $");
vtkStandardNewMacro(vtkDummyController);


//----------------------------------------------------------------------------
void vtkDummyController::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}

