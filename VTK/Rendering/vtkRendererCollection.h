/*=========================================================================

  Program:   OSCAR 
  Module:    $RCSfile: vtkRendererCollection.h,v $
  Language:  C++
  Date:      $Date: 1994-01-18 18:36:10 $
  Version:   $Revision: 1.2 $

Description:
---------------------------------------------------------------------------
This file is part of the vis library

- Ken Martin

=========================================================================*/
#ifndef __vlRendererCollection_hh
#define __vlRendererColleciton_hh

#include "Renderer.hh"

class vlRendererListElement
{
 public:
  vlRenderer *Renderer;
  vlRendererListElement *Next;

};

class vlRendererCollection : public vlObject
{
 public:
  int NumberOfItems;

 private:
  vlRendererListElement *Top;
  vlRendererListElement *Bottom;

 public:
  void Render();
  char *GetClassName() {return "vlRendererCollection";};
  vlRendererCollection();
  void AddMember(vlRenderer *);
  int  GetNumberOfMembers();
  vlRenderer *GetMember(int num);
};

#endif
