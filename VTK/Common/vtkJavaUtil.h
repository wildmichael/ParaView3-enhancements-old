/*=========================================================================

  Program:   Java Wrapper for VTK
  Module:    $RCSfile: vtkJavaUtil.h,v $
  Language:  C++
  Date:      $Date: 1996-11-06 16:26:28 $
  Version:   $Revision: 1.1 $

This file's contents may be copied, reproduced or altered in any way 
without the express written consent of the author.

Copyright (c) Ken Martin 1995

=========================================================================*/

#include <string.h>
extern "C" {
#include <StubPreamble.h>
#include <javaString.h>
}

extern void vtkJavaAddObjectToHash(void *hnd,void *obj,void *tcFunc,int);
extern void *vtkJavaGetPointerFromObject(void *hnd,char *result_type);
extern void vtkJavaDeleteObjectFromHash(void *hnd);
extern void *vtkJavaGetObjectFromPointer(void *hnd);
extern int  vtkJavaShouldIDeleteObject(void *hnd);
 
extern HArrayOfDouble *vtkJavaMakeHArrayOfDoubleFromDouble(double *, int);
extern HArrayOfDouble *vtkJavaMakeHArrayOfDoubleFromFloat(float *, int);
extern HArrayOfInt *vtkJavaMakeHArrayOfIntFromInt(int *, int);


