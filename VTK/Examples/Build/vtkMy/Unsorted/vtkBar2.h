/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkBar2.h,v $
  Language:  C++
  Date:      $Date: 2002-01-04 14:23:30 $
  Version:   $Revision: 1.2 $

=========================================================================*/
// .NAME vtkBar2 - Bar2 class for vtk
// .SECTION Description
// None.

#ifndef __vtkBar2_h
#define __vtkBar2_h

#include "vtkObject.h"
#include "vtkmyUnsortedWin32Header.h"

class VTK_MY_UNSORTED_EXPORT vtkBar2 : public vtkObject
{
public:
  static vtkBar2 *New();
  vtkTypeRevisionMacro(vtkBar2,vtkObject);

protected:
  vtkBar2() {};
  ~vtkBar2() {};
private:
  vtkBar2(const vtkBar2&);  // Not implemented.
  void operator=(const vtkBar2&);  // Not implemented.
};

#endif 
