/*=========================================================================

  Program:   OSCAR 
  Module:    $RCSfile: vtkRenderer.h,v $
  Language:  C++
  Date:      $Date: 1994-01-12 12:31:34 $
  Version:   $Revision: 1.1 $

Description:
---------------------------------------------------------------------------
This file is part of the vis library

- Ken Martin

=========================================================================*/
#ifndef __vlRenderer_hh
#define __vlRenderer_hh

#include "Light.h"
#include "Camera.h"
#include "Actor.h"
#include "GeomPrim.h"

class vlRenderer
{
public:
  vlCamera *ActiveCamera;
  vlLightCollection Lights;
  vlActorCollection Actors;
  float Ambient[3];  
  float Background[3];  
  int BackLight;
  char name[80];

public:
  vlRenderer();
  void AddLights(vlLight *);
  void AddActors(vlActor *);
  void SetActiveCamera(vlCamera *);
  void GetBackground(float *);
  void SetBackground(float ,float ,float);
  virtual void Render() = 0;
  virtual vlActor  *MakeActor() = 0;
  virtual vlLight  *MakeLight() = 0;
  virtual vlCamera *MakeCamera() = 0;
  virtual vlGeometryPrimitive *GetPrimitive(char *) = 0;
};

#endif
