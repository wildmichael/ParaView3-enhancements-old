/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkShrinkPolyData.h,v $
  Language:  C++
  Date:      $Date: 1994-07-13 16:32:36 $
  Version:   $Revision: 1.13 $

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlShrinkPolyData - shrink cells composing PolyData
// .SECTION Description
// vlShrinkPolyData shrinks cells composing PolyData (e.g., vertices, 
// lines, polygons, and triangle strips) towards their centroid. The
// centroid of a cell is computed as the average position of the
// cell points. Shrinking results in disconencting the cells from
// one another.
// .SECTION Caveats
// It is possible to turn cells inside out or cause self intersection
// in special cases.

#ifndef __vlShrinkPolyData_h
#define __vlShrinkPolyData_h

#include "P2PF.hh"

class vlShrinkPolyData : public vlPolyToPolyFilter 
{
public:
  vlShrinkPolyData(float sf=0.5) {this->ShrinkFactor = sf;};
  ~vlShrinkPolyData() {};
  char *GetClassName() {return "vlShrinkPolyData";};
  void PrintSelf(ostream& os, vlIndent indent);

  // Description:
  // Set the fraction of shrink for each cell.
  vlSetClampMacro(ShrinkFactor,float,0.0,1.0);
  // Description:
  // Get the fraction of shrink for each cell.
  vlGetMacro(ShrinkFactor,float);

protected:
  virtual void Execute();
  float ShrinkFactor;
};

#endif
