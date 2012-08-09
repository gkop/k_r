#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 1000

int getop(char[], char []);
void push(double);
double pop(void);
int getline2(char s[], int lim);

main()
{
    int type;
    double op2;
    char s[MAXOP];
    char line[MAXLINE+1];
    int len;

    while (len = getline2(line, MAXLINE) > 0) {
        while ((type = getop(line, s)) != '\0') {
            switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char line[], char s[])
{
    int i, j, c;

    j = 0;
    while ((s[0] = c = line[j]) == ' ' || c == '\t') {
         j++;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        // read an operator, now wipe it out
        line[j] = ' ';
        return c;
    }
    i = 1;
    if (isdigit(c))
        while (isdigit(s[i] = c = line[j+i]))
            i++;
    if (c == '.') {
        i++;
        while (isdigit(s[i] = c = line[j+i]))
            i++;
    }
    s[i] = '\0';
    // got to end of number, now wipe it out
    for (i = j; i < strlen(s) + j; i++)
        line[i] = ' ';
    return NUMBER;
}

int getline2(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
