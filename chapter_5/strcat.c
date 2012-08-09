#include <stdio.h>

void mystrcat(char *s, char *t);

int main()
{
    char a[100] = "sun";
    char b[] = "flower";

    mystrcat(a, b);

    printf("%s\n", a);
    return 0;
}

void mystrcat(char *s, char *t)
{
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) != '\0')
        ;
    *s = '\0';
}
