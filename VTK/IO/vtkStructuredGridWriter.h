/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkStructuredGridWriter.h,v $
  Language:  C++
  Date:      $Date: 1995-02-14 15:31:26 $
  Version:   $Revision: 1.1 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlStructuredGridWriter - write vl structured grid data file
// .SECTION Description
// vlStructuredGridWriter is a source object that writes ASCII or binary 
// polygonal data files in vl format. See text for format details.
// .SECTION Caveats
// Binary files written on one system may not be readable on other systems.

#ifndef __vlStructuredGridWriter_hh
#define __vlStructuredGridWriter_hh

#include "vlDataW.hh"
#include "SGridF.hh"

class vlStructuredGridWriter : public vlDataWriter, public vlStructuredGridFilter
{
public:
  vlStructuredGridWriter() {};
  ~vlStructuredGridWriter() {};
  char *GetClassName() {return "vlStructuredGridWriter";};

protected:
  void WriteData();
  void Execute() {this->Write();};

};

#endif


