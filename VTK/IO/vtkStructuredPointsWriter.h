/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStructuredPointsWriter.h,v $
  Language:  C++
  Date:      $Date: 1995-02-15 10:09:48 $
  Version:   $Revision: 1.2 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlStructuredPointsWriter - write vl structured points data file
// .SECTION Description
// vlStructuredPointsWriter is a source object that writes ASCII or binary 
// structured points data in vl file format. See text for format details.
// .SECTION Caveats
// Binary files written on one system may not be writeable on other systems.

#ifndef __vlStructuredPointsWriter_hh
#define __vlStructuredPointsWriter_hh

#include "vlDataW.hh"
#include "StrPtsF.hh"

class vlStructuredPointsWriter : public vlDataWriter, public vlStructuredPointsFilter
{
public:
  vlStructuredPointsWriter() {};
  ~vlStructuredPointsWriter() {};
  char *GetClassName() {return "vlStructuredPointsWriter";};
  void PrintSelf(ostream& os, vlIndent indent);

  // Multiple inheritance/Object interface
  void Modified();
  unsigned long int GetMTime();
  void DebugOn();
  void DebugOff();

protected:
  void WriteData();
  void Execute() {this->Write();};

};

#endif


