/*
 * $Id: ncio.c,v 1.2 2006-11-29 18:09:27 dcthomp Exp $
 */

#if defined(_CRAY)
#   include "ffio.c"
#else
#   include "posixio.c"
#endif
