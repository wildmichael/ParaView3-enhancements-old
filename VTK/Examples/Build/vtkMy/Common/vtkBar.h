/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkBar.h,v $
  Language:  C++
  Date:      $Date: 2002-01-04 14:23:26 $
  Version:   $Revision: 1.2 $

=========================================================================*/
// .NAME vtkBar - Bar class for vtk
// .SECTION Description
// None.

#ifndef __vtkBar_h
#define __vtkBar_h

#include "vtkObject.h"
#include "vtkmyCommonWin32Header.h"

class VTK_MY_COMMON_EXPORT vtkBar : public vtkObject
{
public:
  static vtkBar *New();
  vtkTypeRevisionMacro(vtkBar,vtkObject);

protected:
  vtkBar() {};
  ~vtkBar() {};
private:
  vtkBar(const vtkBar&);  // Not implemented.
  void operator=(const vtkBar&);  // Not implemented.
};

#endif 
