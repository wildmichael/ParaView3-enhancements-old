/*******************************************************************/
/*                               XDMF                              */
/*                   eXtensible Data Model and Format              */
/*                                                                 */
/*  Id : $Id: XdmfCharArray.h,v 1.3 2003-10-21 15:12:48 andy Exp $  */
/*  Date : $Date: 2003-10-21 15:12:48 $ */
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
#ifndef __XdmfCharArray_h
#define __XdmfCharArray_h

#include "XdmfArray.h"

/*!
This is a special XdmfArray designed to
handle character strings.
*/
class XDMF_EXPORT XdmfCharArray : public XdmfArray {

public:
  XdmfCharArray();
  ~XdmfCharArray();

  XdmfConstString GetClassName() { return ( "XdmfCharArray" ) ; };

//! Get the data as if is were a XdmfString
  XdmfString GetString( void ) {
    return( this->GetDataPointerAsCharPointer() );
    };
//! Set the data from a XdmfString
  XdmfInt32 SetString( XdmfString String ) {
    this->SetDataFromChars( String );
    return( strlen( String ) );
    };
//! Set the Data from a Disk File
  XdmfInt32 SetFromFile( XdmfString FileName );
};

#endif // __XdmfCharArray_h
