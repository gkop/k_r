#include <stdio.h>
#include <math.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[], int w);

int main()
{
    int input = 123;
    int field_width = 6;
    char output[128];

    itoa(input, output, field_width);
    printf("%d becomes %s (field width: %i)\n", input, output, field_width);
}

void itoa(int n, char s[], int w)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    // pad with spaces, if necessary
    for (i = strlen(s); i < w; i++)
        s[i] = ' ';
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
