/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkImplicitFunction.cxx,v $
  Language:  C++
  Date:      $Date: 1995-05-04 16:50:17 $
  Version:   $Revision: 1.1 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#include "ImpFunc.hh"

vlImplicitFunction::vlImplicitFunction()
{
  this->Transform = NULL;
}

// Description:
// Evaluate function at position x-y-z and return value. Point x[3] is
// transformed through transform (if provided).
float vlImplicitFunction::FunctionValue(float x[3])
{
  if ( ! this->Transform )
    {
    return this->EvaluateFunction(x);
    }

  else //pass point through transform
    {
    }
}

// Description:
// Evaluate function gradient at position x-y-z and pass back vector. Point
// x[3] is transformed through transform (if provided).
void vlImplicitFunction::FunctionGradient(float x[3], float g[3])
{
  if ( ! this->Transform )
    {
    return this->EvaluateGradient(x,g);
    }

  else //pass point through transform
    {
    }
}


