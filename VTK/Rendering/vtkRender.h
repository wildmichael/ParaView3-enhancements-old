/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkRender.h,v $
  Language:  C++
  Date:      $Date: 1994-02-06 17:56:40 $
  Version:   $Revision: 1.2 $

This file is part of the Visualization Library. No part of this file or its
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994

=========================================================================*/
#ifndef __Render_hh
#define __Render_hh

// shading models
#define VL_FLAT    0
#define VL_GOURAUD 1
#define VL_PHONG   2

// representation models
#define VL_POINTS    0
#define VL_WIREFRAME 1
#define VL_SURFACE   2

// some general macros
#define RANGE_CLIP(a,x,b) ((x)<(a)?(a):((x)>(b)?(b):(x)))

#endif

