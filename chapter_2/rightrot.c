#include <stdio.h>

/* This driver is borrowed from
   http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_6 */

/* The following function, "getbits", is from K&R p 49 */
/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
   return (x >>(p+1-n)) & ~(~0 << n);
}


/******************************************/
/* asbits - shows integers as bit strings.*/
/* Usage:                                 */
/*         asbits(x, sizeof(x), FLAG)     */
/* FLAG = 1|0, showing if newline desired */
/******************************************/

void asbits(unsigned x, size_t s, int nl)
{
  int i;

  for(i = s*8-1; i>=0; i--) {
     getbits(x, i, 1)? putchar('1') : putchar('0');
     if(!(i%4))putchar(' ');
  }
  if(nl)putchar('\n');
}

int main(void)
{
  int len = 8;
  unsigned x = 0x12345678;

  printf("len: %u\n", len);
  asbits(x,sizeof(x),1);
  asbits(rightrot(x,len),sizeof(x),1);
  //printf("%08x %08x\n",x,rightrot(x,len));
}

int rightrot(int x, int n) {
    // idea is to right rotate x 1 bit at a time, then set left-most bit
    // iff previous value of x had right-most bit set
    int i, mask;
    int bit_was_set;
    for (i = 0; i < n; i++) {
        bit_was_set = (x & 1);
        // right rotate x by one
        x = (x >> 1);
        // we don't know what left-most bit is; it depends on whether the
        // machine chooses to extend the sign during the right shift
        // let's be explicit:
        //   if bit_was_set, set left most bit to 1
        //   else set left most bit to 0
        if (bit_was_set)
            x = x | (1 << (sizeof(x) * 8 - 1));
        else
            x = x & ~(1 << (sizeof(x) * 8 - 1));

    }
    return x;
}
