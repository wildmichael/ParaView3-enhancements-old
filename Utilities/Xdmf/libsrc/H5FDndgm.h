/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: H5FDndgm.h,v 1.2 2003-05-08 14:39:28 clarke Exp $  */
/*  Date : $Date: 2003-05-08 14:39:28 $ */
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
#ifndef H5FDndgm_H
#define H5FDndgm_H

#include "H5Ipublic.h"
#include "H5pubconf.h"

#define H5FD_NDGM  (H5FD_ndgm_init())

#ifndef WIN32
#define __DLL__
#endif

__DLL__ hid_t H5FD_ndgm_init(void);
__DLL__ herr_t H5Pset_fapl_ndgm(hid_t fapl_id, size_t increment, char *host);
__DLL__ herr_t H5Pget_fapl_ndgm(hid_t fapl_id, size_t *increment/*out*/, char **host);

#endif
