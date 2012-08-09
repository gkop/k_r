#include <stdio.h>

void mystrncat(char *s, char *t, int n);

int main()
{
    char a[100] = "sun";
    char b[] = "flower";

    mystrncat(a, b, 0);
    printf("%s\n", a);
    mystrncat(a, b, 4);
    printf("%s\n", a);
    return 0;
}

void mystrncat(char *s, char *t, int n)
{
    while (*s != '\0')
        s++;
    while (n-- > 0 && (*s++ = *t++) != '\0')
        ;
    *s = '\0';
}
