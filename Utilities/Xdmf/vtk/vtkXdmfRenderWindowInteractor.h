/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfRenderWindowInteractor.h,v 1.1 2002-12-02 17:13:54 clarke Exp $  */
/*  Date : $Date: 2002-12-02 17:13:54 $ */
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
#if !defined CYGWIN
#include <vtkXRenderWindowInteractor.h>

class VTK_EXPORT vtkXdmfRenderWindowInteractor : public vtkXRenderWindowInteractor
#else
#include <vtkWin32RenderWindowInteractor.h>

class VTK_EXPORT vtkXdmfRenderWindowInteractor : public vtkWin32RenderWindowInteractor
#endif
{
public:
  static vtkXdmfRenderWindowInteractor *New();
#if !defined CYGWIN
  vtkTypeMacro(vtkXdmfRenderWindowInteractor,vtkXRenderWindowInteractor);
#else
  vtkTypeMacro(vtkXdmfRenderWindowInteractor,vtkWin32RenderWindowInteractor);
#endif
  virtual void LoopOnce();
  virtual void Start( int Block = 0 );
};
