#include <stdio.h>
#define MAXLINE 30

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;
    int lenlen;
    int max;
    char line[MAXLINE];
    char forget[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0) {
        lenlen = 0;
        while (len == MAXLINE - 1) {
            lenlen += len;
            len = getline2(forget, MAXLINE);
        }
        lenlen += len;
 
        if (lenlen > max) {
            max = lenlen;
            copy(longest, line);
        }
    }
    if (max > 0)
      printf("%5d\t%s", max, longest);
    return 0;
}

int getline2(char s[], int lim) {
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
