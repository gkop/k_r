#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
void ungets(char s[]);

char input[1000];

int main()
{
    int c;
    int i = 0;
    while ((c = getch()) != EOF)
        input[i++] = c;
    input[i] = '\0';

    printf("%s\n", input);

    ungets(input);

    i = 0;
    while ((c = getch()) != EOF)
        input[i++] = c;
    input[i] = '\0';

    printf("%s\n", input);
    return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int i;
    for (i=strlen(s)-1; i >= 0; i--) {
        ungetch(s[i]);
    }
}
