/*=========================================================================

  Program:   ParaView
  Module:    $RCSfile: vtkSMChartViewProxy.h,v $

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMChartViewProxy - abstract base class for all Chart Views.
// .SECTION Description
// vtkSMChartViewProxy is an abstract base class for all vtkQtChartViewBase
// subclasses. These are the Qt-based charting views.

#ifndef __vtkSMChartViewProxy_h
#define __vtkSMChartViewProxy_h

#include "vtkSMViewProxy.h"

class vtkQtChartViewBase;
class vtkQtChartWidget;

class VTK_EXPORT vtkSMChartViewProxy : public vtkSMViewProxy
{
public:
  vtkTypeRevisionMacro(vtkSMChartViewProxy, vtkSMViewProxy);
  void PrintSelf(ostream& os, vtkIndent indent);

  //BTX
  // Description:
  // Provides access to the bar chart widget.
  vtkQtChartWidget* GetChartWidget();
  //ETX

  // Description:
  // Provides access to the line chart view.
  vtkQtChartViewBase* GetChartView();

//BTX
protected:
  vtkSMChartViewProxy();
  ~vtkSMChartViewProxy();

  // Description:
  // Called once in CreateVTKObjects() to create a new chart view.
  virtual vtkQtChartViewBase* NewChartView()=0;

  // Description:
  virtual void CreateVTKObjects();

  // Description:
  // Performs the actual rendering. This method is called by
  // both InteractiveRender() and StillRender(). 
  // Default implementation is empty.
  virtual void PerformRender();

  vtkQtChartViewBase* ChartView;
private:
  vtkSMChartViewProxy(const vtkSMChartViewProxy&); // Not implemented
  void operator=(const vtkSMChartViewProxy&); // Not implemented
//ETX
};

#endif
