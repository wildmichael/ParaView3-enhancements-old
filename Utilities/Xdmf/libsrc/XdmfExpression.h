/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: XdmfExpression.h,v 1.2 2003-06-26 18:02:26 andy Exp $  */
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
#include "XdmfArray.h"

XDMF_EXPORT void XdmfArrayExpr( XdmfArray *Array,
    XdmfString Operation, XdmfArray *Values );
XDMF_EXPORT void XdmfScalarExpr( XdmfArray *Array,
    XdmfString Operation, XdmfFloat64 Value);

XDMF_EXPORT XdmfArray *XdmfExpr( XdmfString Statement );

