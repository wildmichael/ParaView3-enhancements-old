/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkNormals.cxx,v $
  Language:  C++
  Date:      $Date: 1994-03-12 19:00:35 $
  Version:   $Revision: 1.4 $

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
//  3D normals, abstract representation
//
#include "Normals.hh"
#include "IdList.hh"
#include "FNormals.hh"

void vlNormals::GetNormals(vlIdList& ptId, vlFloatNormals& fp)
{
  for (int i=0; i<ptId.NumberOfIds(); i++)
    {
    fp.InsertNormal(i,this->GetNormal(ptId.GetId(i)));
    }
}

void vlNormals::PrintSelf(ostream& os, vlIndent indent)
{
  vlObject::PrintSelf(os,indent);

  os << indent << "Number Of Normals: " << this->NumberOfNormals() << "\n";
}
