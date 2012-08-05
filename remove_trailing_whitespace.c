#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0) {
        len--;               
        while (len > 0 && (line[len-1] == ' ' || line[len-1] == '\t')) {
            line[len-1] = '\n';
            line[len] = '\0';            
            len--;    
        }
        if (line[len] == '\n') {
            line[len] = '|';
            line[len+1] = '\n';
            line[len+2] = '\0';
        }
        if (len > 0)
            printf("%s", line);
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
