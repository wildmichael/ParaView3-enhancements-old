/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkDataSetWriter.h,v $
  Language:  C++
  Date:      $Date: 1995-02-14 15:31:23 $
  Version:   $Revision: 1.1 $

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlDataSetWriter - write any type of vl dataset to file
// .SECTION Description
// vlDataSetWriter is an abstract class for mapper objects that write their data
// to disk (or into a communications port).

#ifndef __vlDataSetWriter_hh
#define __vlDataSetWriter_hh

#include "vlDataW.hh"
#include "DataSetF.hh"

class vlDataSetWriter : public vlDataWriter, public vlDataSetFilter
{
public:
  vlDataSetWriter() {};
  ~vlDataSetWriter() {};
  char *GetClassName() {return "vlDataSetWriter";};

protected:
  void WriteData();
  void Execute() {this->Write();};

};

#endif


