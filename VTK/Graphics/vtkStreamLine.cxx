/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStreamLine.cxx,v $
  Language:  C++
  Date:      $Date: 1994-06-07 11:01:41 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#include "StreamL.hh"

vlStreamLine::vlStreamLine()
{

}

void vlStreamLine::Execute()
{

}

void vlStreamLine::PrintSelf(ostream& os, vlIndent indent)
{
  if (this->ShouldIPrint(vlStreamLine::GetClassName()))
    {
    vlDataSetToPolyFilter::PrintSelf(os,indent);

    os << indent << "";
    }

}

