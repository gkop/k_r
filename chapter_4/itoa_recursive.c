#include <stdio.h>
#include <math.h>
#include <string.h>

void itoa(int n, char s[]);

int main()
{
    int input = -4384836;
    char output[128];

    itoa(input, output);
    printf("%d becomes %s\n", input, output);
}

void itoa(int n, char s[])
{
    static int p = 0;

    if (n < 0) {
        s[0] = '-';
        n = -n;
        p++;
    }
    
    if (n >= 10) {
        itoa(n/10, s);
        p++;
    }
    s[p] = n % 10 + '0';
    s[p+1] = '\0';
}
