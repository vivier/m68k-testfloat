
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

#include <fenv.h>
#include "milieu.h"
#include "systmodes.h"
#include "softfloat.h"

/*
-------------------------------------------------------------------------------
Sets the system's IEC/IEEE floating-point rounding mode.
-------------------------------------------------------------------------------
*/
void syst_float_set_rounding_mode( int8 roundingMode )
{

    switch ( roundingMode ) {
    case float_round_nearest_even:
        (void) fesetround( FE_TONEAREST );
        break;
    case float_round_to_zero:
        (void) fesetround( FE_TOWARDZERO );
        break;
    case float_round_up:
        (void) fesetround( FE_UPWARD );
        break;
    case float_round_down:
        (void) fesetround( FE_DOWNWARD );
        break;
    }

}

/*
-------------------------------------------------------------------------------
Does nothing.
-------------------------------------------------------------------------------
*/
void syst_float_set_rounding_precision( int8 precision )
{
    int v;
    asm("fmove.l %%fpcr, %0\n" : "=m" (v));
    switch (precision) {
    case 80:
        v = ( v & ~(3<<6));
        break;
    case 64:
        v = ( v & ~(3<<6)) | (2 << 6);
        break;
    case 32:
        v = ( v & ~(3<<6)) | (1 << 6);
        break;
    }
    asm("fmove.l %0, %%fpcr\n" : : "m" (v));
}

