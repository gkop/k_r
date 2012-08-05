#include <stdio.h>

main()
{
    int c, c_0;
    while ((c = getchar()) != EOF) {
        if (c_0 != ' ' || c != ' ') {
            putchar(c);
        }
        c_0 = c;
    }

}
