/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkQueue.cxx,v $
  Language:  C++
  Date:      $Date: 2002-12-20 17:51:41 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkQueue.txx"
#include "vtkLinkedList.txx"

#ifndef VTK_NO_EXPLICIT_TEMPLATE_INSTANTIATION

template class VTK_EXPORT vtkQueue<void*>;
template class VTK_EXPORT vtkQueue<vtkObject*>;

#endif
