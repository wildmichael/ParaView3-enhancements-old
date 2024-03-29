/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPPairwiseExtractHistogram2D.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*-------------------------------------------------------------------------
  Copyright 2009 Sandia Corporation.
  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
  the U.S. Government retains certain rights in this software.
-------------------------------------------------------------------------*/
// .NAME vtkPPairwiseExtractHistogram2D - compute a 2D histogram between 
//  all adjacent columns of an input vtkTable in parallel.
//
// .SECTION Description
//  This class does exactly the same this as vtkPairwiseExtractHistogram2D,
//  but does it in a multi-process environment.  After each node
//  computes their own local histograms, this class does an AllReduce
//  that distributes the sum of all local histograms onto each node.
//
//  Because vtkPairwiseExtractHistogram2D is a light wrapper around a series
//  of vtkExtractHistogram2D classes, this class just overrides the function
//  that instantiates new histogram filters and returns the parallel version
//  (vtkPExtractHistogram2D).
//
// .SECTION See Also
//  vtkExtractHistogram2D vtkPairwiseExtractHistogram2D vtkPExtractHistogram2D
// 
// .SECTION Thanks
//  Developed by David Feng at Sandia National Laboratories
//------------------------------------------------------------------------------
#ifndef __vtkPPairwiseExtractHistogram2D_h
#define __vtkPPairwiseExtractHistogram2D_h
//------------------------------------------------------------------------------
#include "vtkPairwiseExtractHistogram2D.h"
//------------------------------------------------------------------------------
class vtkExtractHistogram2D;
class vtkMultiProcessController;
//------------------------------------------------------------------------------
class VTK_INFOVIS_EXPORT vtkPPairwiseExtractHistogram2D : public vtkPairwiseExtractHistogram2D
{
public:
  static vtkPPairwiseExtractHistogram2D* New();
  vtkTypeRevisionMacro(vtkPPairwiseExtractHistogram2D, vtkPairwiseExtractHistogram2D);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual void SetController(vtkMultiProcessController*);
  vtkGetObjectMacro(Controller,vtkMultiProcessController);

protected:
  vtkPPairwiseExtractHistogram2D();
  ~vtkPPairwiseExtractHistogram2D();

  vtkMultiProcessController* Controller;

  // Description:
  // Generate a new histogram filter, but actually generate a parallel one this time.
  virtual vtkExtractHistogram2D* NewHistogramFilter();

private:
  vtkPPairwiseExtractHistogram2D(const vtkPPairwiseExtractHistogram2D&); // Not implemented
  void operator=(const vtkPPairwiseExtractHistogram2D&);   // Not implemented
};

#endif
