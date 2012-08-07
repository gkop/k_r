/*
Explanation for exercise 2-9:

The operation x-1 sets the rightmost on bit off, and set all lower-order bits from that bit on.  The higher order bits will be unchanged.

So x & x-1 will always set right-most bit to off.  The lower-bits will not be affected because x-1 sets them to 1.  The higher-order bits will not be affected because they remain the same in both x and x-1.

Edge case of x == 0, when there is no right-most set bit:

If x == 0, then x-1 will set all the bits to on.

If x == 0, then x & x-1 == x, and since there were no bits on in x to begin with, then there is not a right-most bit to delete, and there are still no set bits after the operation.
*/

/* improved bitcount: count 1 bits in x, making use of x &= (x-1) */
int bitcount(unsigned x)
{
    int b = 0;
    while (x > 0) {
        x &= (x-1);
        b++;
    }
    return b;
}
