/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkDataSetMapper.h,v $
  Language:  C++
  Date:      $Date: 1994-02-04 12:49:53 $
  Version:   $Revision: 1.2 $

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// DataSetMapper takes DataSet as input
//
#ifndef __vlDataSetMapper_h
#define __vlDataSetMapper_h

#include "Mapper.hh"
#include "DataSet.hh"
#include "Renderer.hh"

class vlDataSetMapper : public vlMapper 
{
public:
  vlDataSetMapper();
  ~vlDataSetMapper();
  char *GetClassName() {return "vlDataSetMapper";};
  void Render(vlRenderer *ren);
  virtual void SetInput(vlDataSet *in);
  virtual vlDataSet* GetInput();

protected:
  vlDataSet *Input;
  vlMapper *Mapper;
};

#endif


