/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkAppendPolyData.h,v $
  Language:  C++
  Date:      $Date: 1994-06-06 16:14:48 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Appends one or more PolyData datasets together into a single
// PolyData dataset
//
#ifndef __vlAppendPolyData_h
#define __vlAppendPolyData_h

#include "PolyData.hh"
#include "Filter.hh"
#include "PolyDatC.hh"

class vlAppendPolyData : public vlPolyData, public vlFilter
{
public:
  vlAppendPolyData();
  ~vlAppendPolyData();
  char *GetClassName() {return "vlAppendPolyData";};
  void PrintSelf(ostream& os, vlIndent indent);

  void AddInput(vlPolyData *);
  void RemoveInput(vlPolyData *);
  vlPolyDataCollection *GetInput() {return &(this->Input);};

  // filter interface
  void Update();

protected:
  // Usual data generation method
  void Execute();

  // list of data sets to append together
  vlPolyDataCollection Input;
};

#endif


