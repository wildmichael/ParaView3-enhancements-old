/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfXRenderWindowInteractor.h,v 1.1 2003-05-09 17:29:42 clarke Exp $  */
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
#include <vtkXRenderWindowInteractor.h>

class VTK_EXPORT vtkXdmfXRenderWindowInteractor : public vtkXRenderWindowInteractor
{
public:
  static vtkXdmfXRenderWindowInteractor *New();
  vtkTypeMacro(vtkXdmfXRenderWindowInteractor,vtkXRenderWindowInteractor);
  virtual void LoopOnce();
  virtual void Start( int Block = 0 );
};
