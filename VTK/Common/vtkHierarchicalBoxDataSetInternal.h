/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkHierarchicalBoxDataSetInternal.h,v $
  Language:  C++
  Date:      $Date: 2003-12-11 15:47:36 $
  Version:   $Revision: 1.1 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __vtkHierarchicalBoxDataSetInternal_h
#define __vtkHierarchicalBoxDataSetInternal_h

#include "vtkHierarchicalDataSetInternal.h"
#include "vtkAMRBox.h"

struct vtkHierarchicalBoxDataSetInternal
{
  vtkstd::vector<int> RefinementRatios;
};

class vtkHBDSNode : public vtkHDSNode
{
public:
  vtkAMRBox Box;
};

#endif
