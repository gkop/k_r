#include <stdio.h>

#define TAB_LENGTH 8

main()
{
    int c, n, i, spaces_seen, position_in_tab;
    n = 0;
    spaces_seen = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces_seen++;
        }
        else {
            if (spaces_seen == 1) {
                // special case for a single space
                putchar(' ');
                n++;
            }
            else if (spaces_seen > 1) { 
                // first, lets use a tab stop to get to the next tab stop from n
                position_in_tab = n % TAB_LENGTH;
                //printf("position in tab: %d\n", position_in_tab);
                if (TAB_LENGTH - position_in_tab < spaces_seen) {
                    putchar('\t');
                    spaces_seen -= (TAB_LENGTH - position_in_tab);
                    n += (TAB_LENGTH - position_in_tab);
                }
                // now add all the tabs we need
                while (spaces_seen / TAB_LENGTH > 0) {
                    putchar('\t');
                    spaces_seen -= TAB_LENGTH;
                    n += TAB_LENGTH;
                }
                // now finish with spaces
                for (i = 0; i < spaces_seen; i++) {
                    putchar(' ');
                    n++;
                }
            }
            spaces_seen = 0;
            putchar(c);

            if (c == '\n')
                n = 0;
            else
                n++;
        }
    }
}
