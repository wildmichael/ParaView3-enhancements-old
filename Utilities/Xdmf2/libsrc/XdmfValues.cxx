/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Values              */
/*                                                                 */
/*  Id : $Id: XdmfValues.cxx,v 1.1 2006-12-28 21:56:42 clarke Exp $  */
/*  Date : $Date: 2006-12-28 21:56:42 $ */
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
#include "XdmfValues.h"
#include "XdmfDataStructure.h"
#include "XdmfArray.h"

XdmfValues::XdmfValues() {
    this->DataStructure = NULL;
}

XdmfValues::~XdmfValues() {
}

XdmfArray *
XdmfValues::Read(XdmfArray *Array){
    return(NULL);
}

XdmfInt32 
XdmfValues::Write(XdmfArray *Array){
    return(XDMF_FAIL);
}

