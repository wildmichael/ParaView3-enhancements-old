/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfXRenderWindowInteractor.cxx,v 1.1 2003-05-09 17:29:42 clarke Exp $  */
/*  Date : $Date: 2003-05-09 17:29:42 $ */
/*  Version : $Revision: 1.1 $ */
/*                                                                 */
/*  Author:                                                        */
/*     Jerry A. Clarke                                             */
/*     clarke@arl.army.mil                                         */
/*     US Army Research Laboratory                                 */
/*     Aberdeen Proving Ground, MD                                 */
/*                                                                 */
/*     Copyright @ 2002 US Army Research Laboratory                */
/*     All Rights Reserved                                         */
/*     See Copyright.txt or http://www.arl.hpc.mil/ice for details */
/*                                                                 */
/*     This software is distributed WITHOUT ANY WARRANTY; without  */
/*     even the implied warranty of MERCHANTABILITY or FITNESS     */
/*     FOR A PARTICULAR PURPOSE.  See the above copyright notice   */
/*     for more information.                                       */
/*                                                                 */
/*******************************************************************/
#include <vtkXdmfXRenderWindowInteractor.h>


#include <vtkObjectFactory.h>
#include <vtkCommand.h>

//----------------------------------------------------------------------------
vtkXdmfXRenderWindowInteractor* vtkXdmfXRenderWindowInteractor::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkXdmfXRenderWindowInteractor");
  if(ret)
    {
    return (vtkXdmfXRenderWindowInteractor*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkXdmfXRenderWindowInteractor;
}

void vtkXdmfXRenderWindowInteractor::Start( int Block ) {

if ( Block ) {
  vtkXRenderWindowInteractor::Start();
} else {
  this->LoopOnce();
}

}

void vtkXdmfXRenderWindowInteractor::LoopOnce( )
{
    XEvent event;

  if (!this->Initialized)
    {
    this->Initialize();
    }
  if (! this->Initialized )
    {
    return;
    }

    this->BreakLoopFlag = 0;
  while( XtAppPending( this->App )) {
        XtAppNextEvent(this->App, &event);
        XtDispatchEvent(&event);
  }
}
