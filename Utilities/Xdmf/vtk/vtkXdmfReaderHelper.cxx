/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: vtkXdmfReaderHelper.cxx,v 1.1 2002-12-02 17:13:54 clarke Exp $  */
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
#include "vtkXdmfReaderHelper.h"

using namespace std;

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
