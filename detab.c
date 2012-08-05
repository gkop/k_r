#include <stdio.h>

#define TAB_LENGTH 8

main()
{
    int c, n, i, position_in_tab, spaces_needed;
    n = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            position_in_tab = n % TAB_LENGTH;
            spaces_needed = TAB_LENGTH - position_in_tab;
            for (i = 0; i < spaces_needed; i++)
                putchar(' ');
        }
        else {
            putchar(c);

            if (c == '\n')
                n = 0;
            else
                n++;
        }
    }

}
