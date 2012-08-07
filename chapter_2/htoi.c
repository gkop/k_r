#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

const int BUF_SIZE = 128;

unsigned long htoi(char s[]);

main()
{
    char input[BUF_SIZE];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < BUF_SIZE - 1) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    printf("%lu\n", htoi(input));
    return 0;
}

unsigned long htoi(char s[]) {
    unsigned long ret_val = 0;
    int i, v;
    char c;
    for (i = strlen(s) - 1; i >= 0; --i) {
        c = tolower(s[i]);
        if isdigit(c)
            v = c - '0';
        else if ('a' <= c && c <= 'f')
            v = c - 'a' + 10;
        else if (c == 'x' && i > 0 && s[i-1] == '0')
            break;
        else
            v = 0;
       
        ret_val += (v * pow(16, strlen(s) - i - 1));
    }
    return ret_val;
}
