/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkLogLookupTable.cxx,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:25:35 $
  Version:   $Revision: 1.29 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkLogLookupTable.h"
#include "vtkObjectFactory.h"

#include <math.h>

vtkCxxRevisionMacro(vtkLogLookupTable, "$Revision: 1.29 $");
vtkStandardNewMacro(vtkLogLookupTable);

// Construct with (minimum,maximum) range 1 to 10 (based on 
// logarithmic values).
vtkLogLookupTable::vtkLogLookupTable(int sze, int ext) 
  : vtkLookupTable(sze,ext)
{
  this->Scale = VTK_SCALE_LOG10;

  this->TableRange[0] = 1;
  this->TableRange[1] = 10;
}

void vtkLogLookupTable::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
