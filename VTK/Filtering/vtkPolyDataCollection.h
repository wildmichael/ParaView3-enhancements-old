/*=========================================================================

  Program:   Visualization Library
  Module:    $RCSfile: vtkPolyDataCollection.h,v $
  Language:  C++
  Date:      $Date: 1994-06-06 16:13:28 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
#ifndef __vlPolyDataCollection_hh
#define __vlPolyDataCollection_hh

#include "Object.hh"
#include "PolyData.hh"

class vlPolyDataCollectionElement
{
 public:
  vlPolyData *Item;
  vlPolyDataCollectionElement *Next;
};

class vlPolyDataCollection : public vlObject
{
 public:
  int NumberOfItems;

 private:
  vlPolyDataCollectionElement *Top;
  vlPolyDataCollectionElement *Bottom;

 public:
  vlPolyDataCollection();
  void AddItem(vlPolyData *);
  void RemoveItem(vlPolyData *);
  int IsItemPresent(vlPolyData *);
  int GetNumberOfItems();
  vlPolyData *GetItem(int num);
  void PrintSelf(ostream& os, vlIndent indent);
  char *GetClassName() {return "vlPolyDataCollection";};
};

#endif
