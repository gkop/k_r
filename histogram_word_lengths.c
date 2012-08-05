#include <stdio.h>

#define IN  1
#define OUT 0

main()
{
    int c, num, state, i;

    int nchars[10];
    for (i = 0; i < 10; i++) {
      nchars[i] = 0;
    }   

    state = IN;
    num = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (num > 0)
              nchars[num-1]++;
            num = 0;
            state = OUT;
        }
        else if (state == OUT) {
            num = 1;
            state = IN;
        }
        else
          num++;
    }

    for (i = 0; i < 10; i++) {
      printf("%3d %3d\n", i+1, nchars[i]);
    }
}
