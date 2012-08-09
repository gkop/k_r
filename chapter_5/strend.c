#include <stdio.h>
#include <string.h>

int mystrend(char *s, char *t);

int main()
{
    char a[] = "football";
    char b[] = "ball";
    char c[] = "foot";

    printf("strend(%s,%s): %i\n", a, b, mystrend(a,b));
    printf("strend(%s,%s): %i\n", a, c, mystrend(a,c));
    printf("strend(%s,%s): %i\n", c, a, mystrend(c,a));
    printf("strend(%s,%s): %i\n", c, b, mystrend(c,b));
    printf("strend(%s,%s): %i\n", b, b, mystrend(b,b));
    printf("strend(%s,%s): %i\n", "", "", mystrend("",""));
    return 0;
}

int mystrend(char *s, char *t)
{
    int i, j;
    if ((i = strlen(s)-1) < (j = strlen(t)-1))
        return 0;
    for (j; j > 0; i--, j--) {
        if (*(s+i) != *(t+j))
            return 0;
    }
    return 1;
}
