/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkSTLReader.h,v $
  Language:  C++
  Date:      $Date: 1994-02-24 18:15:54 $
  Version:   $Revision: 1.4 $

This file is part of the Visualization Library. No part of this file or its 
contents may be copied, reproduced or altered in any way without the express
written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
//
// Read ASCII/Binary Stereo Lithography Files
//
#ifndef __vlSTLReader_h
#define __vlSTLReader_h

#include <stdio.h>
#include "PolySrc.hh"
#include "FPoints.hh"
#include "CellArr.hh"

class vlSTLReader : public vlPolySource 
{
public:
  vlSTLReader():Filename(0) {};
  char *GetClassName() {return "vlSTLReader";};
  void PrintSelf(ostream& os, vlIndent indent);

  vlSetStringMacro(Filename);
  vlGetStringMacro(Filename);

protected:
  char *Filename;
  void Execute();
  void ReadBinarySTL(FILE *fp, vlFloatPoints*, vlCellArray*);
  void ReadASCIISTL(FILE *fp, vlFloatPoints*, vlCellArray*);
  int GetSTLFileType(FILE *fp);
};

#endif


