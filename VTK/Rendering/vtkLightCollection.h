/*=========================================================================

  Program:   OSCAR 
  Module:    $RCSfile: vtkLightCollection.h,v $
  Language:  C++
  Date:      $Date: 1994-01-17 21:32:54 $
  Version:   $Revision: 1.2 $

Description:
---------------------------------------------------------------------------
This file is part of the vis library

- Ken Martin

=========================================================================*/
#ifndef __vlLightC_hh
#define __vlLightC_hh

#include "Light.hh"

class vlLightListElement
{
 public:
  vlLight *Light;
  vlLightListElement *Next;

};

class vlLightCollection : public vlObject
{
 public:
  int NumberOfItems;

 private:
  vlLightListElement *Top;
  vlLightListElement *Bottom;

 public:
  vlLightCollection();
  virtual char *GetClassName() {return "vlLightCollection";};
  void AddMember(vlLight *);
  int  GetNumberOfMembers();
  vlLight *GetMember(int num);
};

#endif
