/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfReaderHelper.cxx,v 1.2 2003-03-04 15:24:32 andy Exp $  */
/*  Date : $Date: 2003-03-04 15:24:32 $ */
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
#include "vtkXdmfReaderHelper.h"

//---------------------------------------------------------------------------
vtkXdmfReaderHelper::vtkXdmfReaderHelper() {
  this->InputXMLFileName = NULL;
  }

vtkXdmfReaderHelper::~vtkXdmfReaderHelper() {
  if ( this->InputXMLFileName ) {
    delete [] this->InputXMLFileName;
    }
  }

XdmfInt64
vtkXdmfReaderHelper::GetNumberOfPoints(){
  return( this->GetGeometry()->GetNumberOfPoints());
  }
