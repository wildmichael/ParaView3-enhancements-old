/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPVArrowSource.cxx,v $
  Language:  C++
  Date:      $Date: 2003-07-22 22:23:05 $
  Version:   $Revision: 1.2 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPVArrowSource.h"
#include "vtkObjectFactory.h"
#include "vtkPolyData.h"

vtkCxxRevisionMacro(vtkPVArrowSource, "$Revision: 1.2 $");
vtkStandardNewMacro(vtkPVArrowSource);


void vtkPVArrowSource::ExecuteInformation()
{
  this->GetOutput()->SetMaximumNumberOfPieces(-1);
}


void vtkPVArrowSource::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
