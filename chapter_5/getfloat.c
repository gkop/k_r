#include <stdio.h>

#define SIZE 3

int getfloat(double *);

int main()
{
    int n;
    double vals[SIZE];

    for (n = 0; n < SIZE && getfloat(&vals[n]) != EOF; n++)
        ;

    for (n = 0; n < SIZE; n++)
        printf("%.8g ", vals[n]);
    printf("\n");
    return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
    int c, sign;
    double power;

    while (isspace(c=getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn = (sign * *pn / power);
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
