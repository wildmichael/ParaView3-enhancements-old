/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfRenderWindowInteractor.h,v 1.2 2003-04-25 17:24:48 clarke Exp $  */
/*  Date : $Date: 2003-04-25 17:24:48 $ */
/*  Version : $Revision: 1.2 $ */
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

class VTK_EXPORT vtkXdmfRenderWindowInteractor : public vtkXRenderWindowInteractor
{
public:
  static vtkXdmfRenderWindowInteractor *New();
  vtkTypeMacro(vtkXdmfRenderWindowInteractor,vtkXRenderWindowInteractor);
  virtual void LoopOnce();
  virtual void Start( int Block = 0 );
};
