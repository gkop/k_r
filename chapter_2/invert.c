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
  int off = 7;
  int len = 4;
  unsigned x = 0x12345678;

  printf("off: %u  len: %u\n",off,len);
  asbits(x,sizeof(x),1);
  asbits(invert(x,off,len),sizeof(x),1);
  printf("%08x %08x\n",x,invert(x,off,len));
}

int invert(int x, int p, int n) {
    // idea is to XOR x with a mask with n bits at position p set
    int mask;

    // mask out n rightmost bits
    mask = ~(~0 << n);

    // shift mask to line up with position p
    if (p >= n)
        mask = (mask << (p - n + 1));
    else if (n > p)
        mask = (mask >> (n - p - 1));

    // XOR mask with x
    return x ^ mask;
}
