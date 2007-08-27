/*
 * $Id: ncio.c,v 1.4 2007-08-27 23:08:49 dcthomp Exp $
 */

#if defined(_CRAY)
#   include "ffio.c"
#else
#   include "posixio.c"
#endif
