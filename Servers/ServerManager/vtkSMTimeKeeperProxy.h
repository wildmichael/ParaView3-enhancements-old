/*=========================================================================

  Program:   ParaView
  Module:    $RCSfile: vtkSMTimeKeeperProxy.h,v $

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMTimeKeeperProxy - a time keeper is used to keep track of the
// pipeline time.
// .SECTION Description
// TimeKeeper can be thought of as a application wide clock. In ParaView, all
// views are registered with the TimeKeeper (using AddView()) so that all the
// views render data at the same global time.
//
// TimeKeeper also keeps track of time steps and continuous time ranges provided
// by sources/readers/filters. This expects that the readers have a
// "TimestepValues" and/or "TimeRange" properties from which the time steps and
// time ranges provided by the reader can be obtained. All sources whose
// time steps/time ranges must be noted by the time keeper need to be registered
// with the time keeper using AddTimeSource(). ParaView automatically registers
// all created sources/filters/readers with the time keeper. The time steps and
// time ranges are made accessible by two information properties
// "TimestepValues" and "TimeRange" on the TimeKeeper proxy.
// 
// To change the time shown by all the views, simply change the "Time" property
// on the time keeper proxy (don't directly call SetTime() since otherwise
// undo/redo, state etc. will not work as expected).
//
// This proxy has no VTK objects that it creates on the server.

#ifndef __vtkSMTimeKeeperProxy_h
#define __vtkSMTimeKeeperProxy_h

#include "vtkSMProxy.h"

class vtkSMViewProxy;
class vtkSMSourceProxy;

class VTK_EXPORT vtkSMTimeKeeperProxy : public vtkSMProxy
{
public:
  static vtkSMTimeKeeperProxy* New();
  vtkTypeRevisionMacro(vtkSMTimeKeeperProxy, vtkSMProxy);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Get/Set the pipeline time.
  void SetTime(double time);
  vtkGetMacro(Time, double);

  // Description:
  // Add/Remove view proxy linked to this time keeper.
  void AddView(vtkSMViewProxy*);
  void RemoveView(vtkSMViewProxy*);
  void RemoveAllViews();

  // Description:
  // List of proxies that provide time. TimestepValues property has a set of
  // timesteps provided by all the sources added to this property alone.
  void AddTimeSource(vtkSMSourceProxy*);
  void RemoveTimeSource(vtkSMSourceProxy*);
  void RemoveAllTimeSources();

//BTX
protected:
  vtkSMTimeKeeperProxy();
  ~vtkSMTimeKeeperProxy();

  vtkCommand* Observer;
  void UpdateTimeSteps();

  double Time;
private:
  vtkSMTimeKeeperProxy(const vtkSMTimeKeeperProxy&); // Not implemented
  void operator=(const vtkSMTimeKeeperProxy&); // Not implemented

  class vtkInternal;
  vtkInternal* Internal;
//ETX
};

#endif

