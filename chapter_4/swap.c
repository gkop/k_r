#include <stdio.h>

#define swap(t,a,b) \
{                   \
    t tmp = a;      \
    a = b;          \
    b = tmp;        \
}

int main()
{
    int a = 7;
    int b = 11;
    char c = 'a';
    char d = 'z';

    printf("swap(%i,%i) is ", a, b);
    swap(int, a, b);
    printf("%i,%i\n", a, b);

    printf("swap(%c,%c) is ", c, d);
    swap(char, c, d);
    printf("%c,%c\n", c, d);

    return 0;
}
