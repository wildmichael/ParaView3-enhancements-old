/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfOpenGLCamera.h,v 1.3 2004-04-27 17:46:25 andy Exp $  */
/*  Date : $Date: 2004-04-27 17:46:25 $ */
/*  Version : $Revision: 1.3 $ */
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
#ifndef _vtkXdmfOpenGLCamera_h
#define _vtkXdmfOpenGLCamera_h

#include "vtkOpenGLCamera.h"

class VTK_EXPORT vtkXdmfOpenGLCamera : public vtkOpenGLCamera
{
public:
  static vtkXdmfOpenGLCamera *New();
  vtkTypeMacro(vtkXdmfOpenGLCamera, vtkOpenGLCamera);
  virtual void SetReallyLeft( int rl )
    {
    this->ReallyLeft = rl;
    }
  virtual int GetReallyLeft(void)
    {
    return(this->ReallyLeft);
    }
  virtual void Render(vtkRenderer *ren);
protected:
  int     ReallyLeft;
  vtkXdmfOpenGLCamera()
    {
    this->ReallyLeft = 0;
    }
  
private:
  vtkXdmfOpenGLCamera(const vtkXdmfOpenGLCamera&); // Not implemented
  void operator=(const vtkXdmfOpenGLCamera&); // Not implemented
};

#endif
