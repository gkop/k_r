#include <stdio.h>

const int LINE_LENGTH = 20;

void left_shift_string(char s[], int n);

int main()
{
    int c, i, n, index_of_last_non_blank;

    char buf[LINE_LENGTH];
    n = 0;
    index_of_last_non_blank = -1; // sentinel for lines of only blanks
    while ((c = getchar()) != EOF) {
        buf[n] = c;

        if (c != ' ')
            index_of_last_non_blank = n;

        if (c == '\n') {
            // flush buffer
            for (i = 0; i <= n; i++)
                putchar(buf[i]);
            n = 0;
        }
        else if (n == LINE_LENGTH - 1) {
             // time to fold the long line

             if (index_of_last_non_blank < 0)
                 // no non-blanks; use last blank instead
                 index_of_last_non_blank = n - 1;

             // output buf up to and including last non-blank character
             for (i = 0; i <= index_of_last_non_blank; i++)
                 putchar(buf[i]);

             // forget about the chars just output
             left_shift_string(buf, index_of_last_non_blank + 1);
             n = n - index_of_last_non_blank;
             index_of_last_non_blank = -1;

             putchar('\n');
        }
        else {
            n++;
        }
    }
    // flush buffer
    for (i = 0; i < n; i++)
        putchar(buf[i]);
}

void left_shift_string(char s[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        s[i] = s[i + n];
    }
}
