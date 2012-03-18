
/*
===============================================================================

This C source file is part of TestFloat, Release 2a, a package of programs
for testing the correctness of floating-point arithmetic complying to the
IEC/IEEE Standard for Floating-Point.

Written by John R. Hauser.  More information is available through the Web
page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.

THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort
has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT
TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO
PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY
AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.

Derivative works are acceptable, even for commercial purposes, so long as
(1) they include prominent notice that the work is derivative, and (2) they
include prominent notice akin to these four paragraphs for those parts of
this code that are retained.

===============================================================================
*/

#include <stdlib.h>
#include <fenv.h>
#include "milieu.h"
#include "softfloat.h"
#include "systflags.h"

/*
-------------------------------------------------------------------------------
Clears the system's IEC/IEEE floating-point exception flags.  Returns the
previous value of the flags.
-------------------------------------------------------------------------------
*/
int8 syst_float_flags_clear( void )
{
    int eflags;
    int ret;

    eflags = fetestexcept( FE_ALL_EXCEPT );

    ret = feclearexcept( FE_ALL_EXCEPT );
    if ( ret == -1) {
        perror("syst_float_flags_clear():");
        exit(1);
    }

    ret = 0;
#if defined(FE_INEXACT)
    if ( eflags & FE_INEXACT ) {
        ret |= float_flag_inexact;
    }
#endif
#if defined(FE_DIVBYZERO)
    if ( eflags & FE_DIVBYZERO ) {
        ret |= float_flag_divbyzero;
    }
#endif
#if defined(FE_UNDERFLOW)
    if ( eflags & FE_UNDERFLOW ) {
        ret |= float_flag_underflow;
    }
#endif
#if defined(FE_OVERFLOW)
    if ( eflags & FE_OVERFLOW ) {
        ret |= float_flag_overflow;
    }
#endif
#if defined(FE_INVALID)
    if ( eflags & FE_INVALID ) {
        ret |= float_flag_invalid;
    }
#endif
    return ret;
}

