/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPerturbCoincidentVertices.h,v $

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
// .NAME vtkPerturbCoincidentVertices - Perturbs vertices that are coincident.
//
// .SECTION Description
// This filter perturbs vertices in a graph that have coincident coordinates.
// In particular this happens all the time with graphs that are georeferenced,
// so we need a nice scheme to perturb the vertices so that when the user
// zooms in the vertices can be distiquished.

#ifndef __vtkPerturbCoincidentVertices_h
#define __vtkPerturbCoincidentVertices_h

#include "vtkGraphAlgorithm.h"
#include "vtkSmartPointer.h" // for ivars

class vtkCoincidentPoints;
class vtkDataSet;

class VTK_INFOVIS_EXPORT vtkPerturbCoincidentVertices : public vtkGraphAlgorithm
{
public:
  static vtkPerturbCoincidentVertices* New();
  vtkTypeRevisionMacro(vtkPerturbCoincidentVertices,vtkGraphAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Specify the perturbation factor (defaults to 1.0)
  vtkSetMacro(PerturbFactor,double);
  vtkGetMacro(PerturbFactor,double);

protected:
  vtkPerturbCoincidentVertices();
  ~vtkPerturbCoincidentVertices();

  int RequestData(
    vtkInformation*, 
    vtkInformationVector**, 
    vtkInformationVector*);

private:

  // This class might have more than one method of coincident resolution
  void SpiralPerturbation(vtkGraph *input, vtkGraph *output);
  void SimpleSpiralPerturbation(vtkGraph *input, vtkGraph *output, float perturbFactor);

  float PerturbFactor;

  vtkPerturbCoincidentVertices(const vtkPerturbCoincidentVertices&); // Not implemented
  void operator=(const vtkPerturbCoincidentVertices&);   // Not implemented
};

#endif

