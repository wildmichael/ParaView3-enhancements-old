/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkCellArray.cxx,v $
  Language:  C++
  Date:      $Date: 1994-03-12 19:03:14 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#include "CellArr.hh"

vlCellArray::vlCellArray (const vlCellArray& ca)
{
  this->NumberOfCells = ca.NumberOfCells;
  this->Location = 0;
  this->Ia = ca.Ia;
}
