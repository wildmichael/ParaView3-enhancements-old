/*=========================================================================

Program:   Visualization Toolkit
Module:    $RCSfile: vtkBar.cxx,v $
Language:  C++
Date:      $Date: 2001-12-19 23:17:39 $
Version:   $Revision: 1.1 $

=========================================================================*/
#include "vtkBar.h"
#include "vtkObjectFactory.h"

//----------------------------------------------------------------------------

vtkBar* vtkBar::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkBar");
  if(ret)
    {
    return (vtkBar*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkBar;
}
