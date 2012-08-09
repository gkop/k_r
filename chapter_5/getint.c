#include <stdio.h>

#define SIZE 3

int getline2(char line[], int maxline);
int getint(int *);

int main()
{
    int n, vals[SIZE];

    for (n = 0; n < SIZE && getint(&vals[n]) != EOF; n++)
        ;

    for (n = 0; n < SIZE; n++)
        printf("%d ", vals[n]);
    printf("\n");
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;
    int sign_char = 0;

    while (isspace(c=getch()) || c == '+' || c == '-') {
      if (c == '+' || c == '-')
          sign_char = c;
    }
    if (!isdigit(c) && c != EOF) {
        ungetch(c);
        return 0;
    }
    sign = (sign_char == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
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
