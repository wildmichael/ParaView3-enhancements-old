/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfWin32RenderWindowInteractor.cxx,v 1.1 2003-05-09 17:29:42 clarke Exp $  */
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
#include <vtkXdmfWin32RenderWindowInteractor.h>


#include <vtkObjectFactory.h>
#include <vtkCommand.h>

//----------------------------------------------------------------------------
vtkXdmfWin32RenderWindowInteractor* vtkXdmfWin32RenderWindowInteractor::New()
{
  // First try to create the object from the vtkObjectFactory
  vtkObject* ret = vtkObjectFactory::CreateInstance("vtkXdmfWin32RenderWindowInteractor");
  if(ret)
    {
    return (vtkXdmfWin32RenderWindowInteractor*)ret;
    }
  // If the factory was unable to create the object, then create it here.
  return new vtkXdmfWin32RenderWindowInteractor;
}

void vtkXdmfWin32RenderWindowInteractor::Start( int Block ) {

if ( Block ) {
// Check for WIN32 but without Cygwin with X11
  vtkWin32RenderWindowInteractor::Start();
} else {
  this->LoopOnce();
}

}

void vtkXdmfWin32RenderWindowInteractor::LoopOnce( )
{
MSG msg;
while (PeekMessage ( &msg, NULL, 0, 0, PM_NOREMOVE) {
	if(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);	
		}
	}
}
