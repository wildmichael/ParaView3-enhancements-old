/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageMapToRGBA.h,v $
  Language:  C++
  Date:      $Date: 2002-01-22 15:33:01 $
  Version:   $Revision: 1.20 $

  Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen 
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageMapToRGBA - map the input image through a lookup table
// .SECTION Description
// This filter has been replaced by vtkImageMapToColors, which provided
// additional features.  Use vtkImageMapToColors instead.

// .SECTION See Also
// vtkLookupTable

#ifndef __vtkImageMapToRGBA_h
#define __vtkImageMapToRGBA_h


#include "vtkImageMapToColors.h"

class VTK_IMAGING_EXPORT vtkImageMapToRGBA : public vtkImageMapToColors
{
public:
  static vtkImageMapToRGBA *New();
  vtkTypeRevisionMacro(vtkImageMapToRGBA,vtkImageMapToColors);

protected:
  vtkImageMapToRGBA() {};
  ~vtkImageMapToRGBA() {};
private:
  vtkImageMapToRGBA(const vtkImageMapToRGBA&);  // Not implemented.
  void operator=(const vtkImageMapToRGBA&);  // Not implemented.
};

#endif







