/*=========================================================================

  Program:   OSCAR 
  Module:    $RCSfile: vtkLightCollection.h,v $
  Language:  C++
  Date:      $Date: 1994-01-18 18:36:09 $
  Version:   $Revision: 1.3 $

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
  char *GetClassName() {return "vlLightCollection";};
  void AddMember(vlLight *);
  int  GetNumberOfMembers();
  vlLight *GetMember(int num);
};

#endif
