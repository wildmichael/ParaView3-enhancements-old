/*=========================================================================

  Program:   OSCAR 
  Module:    $RCSfile: vtkRenderer.h,v $
  Language:  C++
  Date:      $Date: 1994-01-18 18:36:11 $
  Version:   $Revision: 1.4 $

Description:
---------------------------------------------------------------------------
This file is part of the vis library

- Ken Martin

=========================================================================*/
#ifndef __vlRenderer_hh
#define __vlRenderer_hh

#include "Object.hh"
#include "LightC.hh"
#include "Camera.hh"
#include "ActorC.hh"
#include "GeomPrim.hh"

class vlRenderer : public vlObject
{
public:
  vlCamera *ActiveCamera;
  vlLightCollection Lights;
  vlActorCollection Actors;
  float Ambient[3];  
  float Background[3];  
  int BackLight;

public:
  vlRenderer();
  char *GetClassName() {return "vlRenderer";};
  void AddLights(vlLight *);
  void AddActors(vlActor *);
  void SetActiveCamera(vlCamera *);

  vlSetVector3Macro(Background,float);
  vlGetVectorMacro(Background,float);

  vlSetVector3Macro(Ambient,float);
  vlGetVectorMacro(Ambient,float);

  vlSetMacro(BackLight,int);
  vlGetMacro(BackLight,int);
  vlBooleanMacro(BackLight,int);

  virtual void Render() = 0;
  virtual vlGeometryPrimitive *GetPrimitive(char *) = 0;
};

#endif
