/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: XdmfHDFSupport.h,v 1.2 2003-06-26 18:02:26 andy Exp $  */
/*  Date : $Date: 2003-06-26 18:02:26 $ */
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
#ifndef __XdmfHDFSupport_h
#define __XdmfHDFSupport_h

#ifndef SWIG
#include "XdmfObject.h"
extern "C" {
#include "hdf5.h"
}
#endif

extern XDMF_EXPORT hid_t    XdmfTypeToHDF5Type( XdmfInt32 XdmfType );
extern XDMF_EXPORT XdmfInt32  HDF5TypeToXdmfType( hid_t HDF5Type );
extern XDMF_EXPORT XdmfString  XdmfTypeToString( XdmfInt32 XdmfType );
extern XDMF_EXPORT XdmfInt32  StringToXdmfType( XdmfString TypeName );
extern XDMF_EXPORT XdmfString  XdmfTypeToClassString( XdmfInt32 XdmfType );


#endif // __XdmfHDFSupport_h
