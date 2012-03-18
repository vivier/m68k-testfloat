
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

#include <math.h>
#include "milieu.h"
#include "softfloat.h"
#include "systfloat.h"

float32 syst_int32_to_float32( int32 a )
{
    float32 z;

    asm("fmovel %1, %%fp0\n"
        "fmoves %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

float64 syst_int32_to_float64( int32 a )
{
    float64 z;

    asm("fmovel %1, %%fp0\n"
        "fmoved %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

floatx80 syst_int32_to_floatx80( int32 a )
{
    floatx80 z;

    asm("fmovel %1, %%fp0\n"
        "fmovex %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

float64 syst_float32_to_float64( float32 a )
{
    float64 z;

    asm("fmoves %1, %%fp0\n"
        "fmoved %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

floatx80 syst_float32_to_floatx80( float32 a )
{
    floatx80 z;

    asm("fmoves %1, %%fp0\n"
        "fmovex %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

float32 syst_float32_add( float32 a, float32 b )
{
    float32 z;

    asm("fmoves %2, %%fp0\n"
        "fadds %1,%%fp0\n"
	"fmoves %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float32 syst_float32_sub( float32 a, float32 b )
{
    float32 z;

    asm("fmoves %1, %%fp0\n"
        "fsubs %2,%%fp0\n"
	"fmoves %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float32 syst_float32_mul( float32 a, float32 b )
{
    float32 z;

    asm("fmoves %2, %%fp0\n"
        "fmuls %1,%%fp0\n"
	"fmoves %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float32 syst_float32_div( float32 a, float32 b )
{
    float32 z;

    asm("fmoves %1, %%fp0\n"
        "fdivs %2,%%fp0\n"
	"fmoves %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

flag syst_float32_eq( float32 a, float32 b )
{

    return ( *( (float *) &a ) == *( (float *) &b ) );

}

flag syst_float32_le( float32 a, float32 b )
{

    return ( *( (float *) &a ) <= *( (float *) &b ) );

}

flag syst_float32_lt( float32 a, float32 b )
{

    return ( *( (float *) &a ) < *( (float *) &b ) );

}

float32 syst_float64_to_float32( float64 a )
{
    float32 z;

    asm("fmoved %1, %%fp0\n"
        "fmoves %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

floatx80 syst_float64_to_floatx80( float64 a )
{
    floatx80 z;

    asm("fmoved %1, %%fp0\n"
        "fmovex %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

float64 syst_float64_add( float64 a, float64 b )
{
    float64 z;

    asm("fmoved %2, %%fp0\n"
        "faddd %1,%%fp0\n"
	"fmoved %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float64 syst_float64_sub( float64 a, float64 b )
{
    float64 z;

    asm("fmoved %1, %%fp0\n"
        "fsubd %2,%%fp0\n"
	"fmoved %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float64 syst_float64_mul( float64 a, float64 b )
{
    float64 z;

    asm("fmoved %2, %%fp0\n"
        "fmuld %1,%%fp0\n"
	"fmoved %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float64 syst_float64_div( float64 a, float64 b )
{
    float64 z;

    asm("fmoved %1, %%fp0\n"
        "fdivd %2,%%fp0\n"
	"fmoved %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

float64 syst_float64_sqrt( float64 a )
{
    float64 z;

    asm("fsqrtd %1,%%fp0\n"
	"fmoved %%fp0, %0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

flag syst_float64_eq( float64 a, float64 b )
{

    return ( *( (double *) &a ) == *( (double *) &b ) );

}

flag syst_float64_le( float64 a, float64 b )
{

    return ( *( (double *) &a ) <= *( (double *) &b ) );

}

flag syst_float64_lt( float64 a, float64 b )
{

    return ( *( (double *) &a ) < *( (double *) &b ) );

}

float32 syst_floatx80_to_float32( floatx80 a )
{
    float32 z;

    asm("fmovex %1, %%fp0\n"
        "fmoves %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

float64 syst_floatx80_to_float64( floatx80 a )
{
    float64 z;

    asm("fmovex %1, %%fp0\n"
        "fmoved %%fp0,%0\n" : "=m" (z) : "m" (a) : "fp0" );

    return z;

}

floatx80 syst_floatx80_add( floatx80 a, floatx80 b )
{
    floatx80 z;

    asm("fmovex %2, %%fp0\n"
        "faddx %1,%%fp0\n"
	"fmovex %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

floatx80 syst_floatx80_sub( floatx80 a, floatx80 b )
{
    floatx80 z;

    asm("fmovex %1, %%fp0\n"
        "fsubx %2,%%fp0\n"
	"fmovex %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

floatx80 syst_floatx80_mul( floatx80 a, floatx80 b )
{
    floatx80 z;

    asm("fmovex %2, %%fp0\n"
        "fmulx %1,%%fp0\n"
	"fmovex %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

floatx80 syst_floatx80_div( floatx80 a, floatx80 b )
{
    floatx80 z;

    asm("fmovex %1, %%fp0\n"
        "fdivx %2,%%fp0\n"
	"fmovex %%fp0, %0\n" : "=m" (z) : "m" (a), "m" (b) : "fp0" );

    return z;

}

flag syst_floatx80_eq( floatx80 a, floatx80 b )
{

    return ( *( (long double *) &a ) == *( (long double *) &b ) );

}

flag syst_floatx80_le( floatx80 a, floatx80 b )
{

    return ( *( (long double *) &a ) <= *( (long double *) &b ) );

}

flag syst_floatx80_lt( floatx80 a, floatx80 b )
{

    return ( *( (long double *) &a ) < *( (long double *) &b ) );

}
