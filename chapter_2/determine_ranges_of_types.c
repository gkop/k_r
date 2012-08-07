#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
    int i;
    signed long min, max;
    unsigned long max_unsigned;
    char signed_char;
    short signed_short;
    int signed_int;
    long signed_long;
    unsigned char unsigned_char;
    unsigned short unsigned_short;
    unsigned int unsigned_int;
    unsigned long unsigned_long;

    // from headers first
    printf("signed char:\t(%i .. %i)\n", CHAR_MIN, CHAR_MAX);
    printf("signed short:\t(%i .. %i)\n", SHRT_MIN, SHRT_MAX);
    printf("signed int:\t(%i .. %i)\n", INT_MIN, INT_MAX);
    printf("signed long:\t(%ld .. %ld)\n", LONG_MIN, LONG_MAX);

    printf("unsigned char:\t(%i .. %i)\n", 0, UCHAR_MAX);
    printf("unsigned short:\t(%i .. %i)\n", 0, USHRT_MAX);
    printf("unsigned int:\t(%i .. %u)\n", 0, UINT_MAX);
    printf("unsigned long:\t(%i .. %lu)\n", 0, ULONG_MAX);

    // now by direct computation
    min = signed_char = 0;
    while (--signed_char <= -1)
        min--;

    max = signed_char = 0;
    while (++signed_char > 0)
        max++;

    printf("signed char:\t(%ld .. %ld)\n", min, max);

    min = signed_short = 0;
    while (--signed_short <= -1)
        min--;

    max = signed_short = 0;
    while (++signed_short > 0)
        max++;

    printf("signed short:\t(%ld .. %ld)\n", min, max);

/*
    min = signed_int = 0;
    while (--signed_int <= -1)
        min--;

    max = signed_int = 0;
    while (++signed_int > 0)
        max++;

    printf("signed int:\t(%ld .. %ld)\n", min, max);

    // this is where i figured out K&R have something else in mind :)
*/

    min = (pow(2, sizeof(signed_int) * 8) / 2) * -1;
    max = pow(2, sizeof(signed_int) * 8) / 2 - 1;
    printf("signed int:\t(%ld .. %ld)\n", min, max);

    min = (pow(2, sizeof(signed_long) * 8) / 2) * -1;
    max = (long)(pow(2, sizeof(signed_long) * 8) / 2 -1);
    printf("signed long:\t(%ld .. %ld)\n", min, max);

    min = 0;
    max = pow(2, sizeof(unsigned_char) * 8) - 1;
    printf("unsigned char:\t(%ld .. %ld)\n", min, max);

    max = pow(2, sizeof(unsigned_short) * 8) - 1;
    printf("unsigned short:\t(%ld .. %ld)\n", min, max);

    max = pow(2, sizeof(unsigned_int) * 8) - 1;
    printf("unsigned int:\t(%ld .. %ld)\n", min, max);

    max_unsigned = (unsigned long)(pow(2, sizeof(unsigned_long) * 8) - 1);
    printf("unsigned long:\t(%ld .. %lu)\n", min, max_unsigned);

    // TODO: come back to floats
}
