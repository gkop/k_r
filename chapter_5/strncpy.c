#include <stdio.h>

void mystrncpy(char *s, char *t, int n);

int main()
{
    char a[] = "football";
    char b[10] = "";
    int n;

    mystrncpy(b,a,n=1);
    printf("strncpy('',%s,%i): %s\n", a, n, b);
    b[0] = '\0';
    mystrncpy(b,a,n=0);
    printf("strncpy('',%s,%i): %s\n", a, n, b);
    b[0] = '\0';
    mystrncpy(b,a,n=100);
    printf("strncpy('',%s,%i): %s\n", a, n, b);
    return 0;
}

void mystrncpy(char *s, char *t, int n)
{
    while(n-- > 0 && (*s++ = *t++))
        ;
}
