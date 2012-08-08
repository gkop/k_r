#include <stdio.h>
#include <math.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main()
{
    int input = -10000;
    char output[128];
    int radix = 8;

    itob(input, output, radix);
    printf("%d becomes %ir%s\n", input, radix, output);
}

void itob(int n, char s[], int b)
{
    int i, sign, y;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        y = n % b;
        if (y < 10)
          s[i++] = y + '0';
        else
          s[i++] = y - 10 + 'a';
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int len, i, tmp;
    // find the length first;
    len = 0;
    while (s[len] != '\0')
        len++;

    for (i = 0; i < (len / 2); i++) {
        tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
}
