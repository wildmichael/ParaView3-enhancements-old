/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkNormals.cxx,v $
  Language:  C++
  Date:      $Date: 1994-02-04 12:47:40 $
  Version:   $Revision: 1.2 $

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
  for (int i=0; i<ptId.NumIds(); i++)
    {
    fp.InsertNormal(i,this->GetNormal(ptId[i]));
    }
}

void vlNormals::PrintSelf(ostream& os, vlIndent indent)
{
  vlObject::PrintSelf(os,indent);

  os << indent << "Number normals: " << this->NumNormals() << "\n";
}
