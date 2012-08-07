#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void reverse(char s[]);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int getline2(char s[], int lim) {
    int c, i;

    i = 0;
    while (i < lim-1) {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            break;
        else
            s[i] = c;
        ++i;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int len, i, tmp;
    // find the length first;
    len = 0;
    while (s[len] != '\0')
        len++;

    for (i = 0; i < (len / 2); i++) {
        tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
}

