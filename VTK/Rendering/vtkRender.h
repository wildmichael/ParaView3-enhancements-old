/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkRender.h,v $
  Language:  C++
  Date:      $Date: 1995-06-30 16:29:03 $
  Version:   $Revision: 1.4 $

This file is part of the Visualization Toolkit. No part of this file or its
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994

=========================================================================*/
#ifndef __Render_hh
#define __Render_hh

// shading models
#define VTK_FLAT    0
#define VTK_GOURAUD 1
#define VTK_PHONG   2

// representation models
#define VTK_POINTS    0
#define VTK_WIREFRAME 1
#define VTK_SURFACE   2

// some general macros
#define RANGE_CLIP(a,x,b) ((x)<(a)?(a):((x)>(b)?(b):(x)))

#endif

