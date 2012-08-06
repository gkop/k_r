#include <stdio.h>

#define IN  1
#define OUT 0

main()
{
    int c, state;

    state = IN;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        else if (state == OUT) {
            putchar('\n');
            state = IN;
        }

        if (c != '\n')
            putchar(c);
    }
}
