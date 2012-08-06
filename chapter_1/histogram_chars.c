#include <stdio.h>

#define IN  1
#define OUT 0

// TODO come back to this when I know more about sorting and/or structs

main()
{
    int i, c;

    int chars[256];

    for (i = 0; i < 256; i++) {
      chars[i] = 0;
    }
 
    while ((c = getchar()) != EOF) {
      chars[c]++;
    }

    for (i = 32; i <= 126; i++) {
      printf("%3d %3c %3d\n", i, i, chars[i]);
    }
}
