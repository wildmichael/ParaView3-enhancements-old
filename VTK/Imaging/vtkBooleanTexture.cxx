/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkBooleanTexture.cxx,v $
  Language:  C++
  Date:      $Date: 1994-11-09 19:53:02 $
  Version:   $Revision: 1.3 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#include "BoolText.hh"

vlBooleanTexture::vlBooleanTexture()
{
}

void vlBooleanTexture::PrintSelf(ostream& os, vlIndent indent)
{
  vlObject::PrintSelf(os,indent);

  os << indent << "Thickness: " << this->Thickness << "\n";
}

