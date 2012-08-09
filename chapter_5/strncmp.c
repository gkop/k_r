#include <stdio.h>
#include <string.h>

int mystrncmp(char *s, char *t, int n);

int main()
{
    char a[] = "football";
    char b[] = "foosball";
    char c[] = "jackelope";

    printf("strncmp(%s,%s,0): %i\n", a, b, mystrncmp(a,b, 0));
    printf("strncmp(%s,%s,1): %i\n", a, b, mystrncmp(a,b, 1));
    printf("strncmp(%s,%s,2): %i\n", a, b, mystrncmp(a,b, 2));
    printf("strncmp(%s,%s,3): %i\n", a, b, mystrncmp(a,b, 3));
    printf("strncmp(%s,%s,4): %i\n", a, b, mystrncmp(a,b, 4));
    printf("strncmp(%s,%s,10): %i\n", a, c, mystrncmp(a,c, 10));
    printf("strncmp(%s,%s,0): %i\n", a, c, mystrncmp(a,c, 0));
    printf("strncmp(%s,%s,10): %i\n", c, a, mystrncmp(c,a, 10));
    return 0;
}

int mystrncmp(char *s, char *t, int n)
{
    for ( ; n == 0 || *s == *t; s++, t++, n--)
        if (n <= 1)
            return 0;
    return *s - *t;
}
