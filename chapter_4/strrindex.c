#include <stdio.h>
#include <string.h>

int strrindex(char source[], char searchfor[]);

char pattern[] = "oo";
char text[] = "Kangaroo zoologist";

int main()
{
    int p1 = strindex(text, pattern);
    int p2 = strrindex(text, pattern);
    printf("strindex(\"%s\", \"%s\") is %i\n", text, pattern, p1);
    printf("strrindex(\"%s\", \"%s\") is %i\n", text, pattern, p2);
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i=strlen(s)-1; i >= 0; i--) {
        for (j=i, k=strlen(t)-1; j >= 0 && k >= 0 && s[j]==t[k]; j--, k--)
            ;
        if (k < 0)
            return j+1;
    }
    return -1;
}
