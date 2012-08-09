#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void reverse(char s[]);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

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

void reverse(char s[]) {
    static int p = 0;
    int i, tmp;
    if (p < strlen(s) / 2) {
        tmp = s[p];
        s[p] = s[strlen(s)-1-p];
        s[strlen(s)-1-p] = tmp;
        p++;
        reverse(s);
    }
}

