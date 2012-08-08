#include <stdio.h>
#include <math.h>

/* explanation for exercise: the function on pg. 64 deals with negatives by
   multiplying them by -1 before converting them to strings.  the largest
   negative number in 2's complement, when multiplied by -1, is out of range for
   its own data type, so the function doesn't work for that input.
*/

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    int input = -1 * pow(2, sizeof(input) * 8 - 1);
    char output[128];

    itoa(input, output);
    printf("%d becomes %s\n", input, output);
}

void itoa(int n, char s[])
{
    int i, sign, special, y;
    if (n == -1 * pow(2, sizeof(n) * 8 - 1)) {
        // special case for when n is the largest negative number
        n++;
        special = 1;
    }
    else {
        special = 0;
    }

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        y =  n % 10;
        if (special) {
            if (y < 9) {
                // bump current digit by 1
                y++;
            }
            else {
                // current digit will be 0
                y = 0;
                // carry the 10
                n += 10;
            }
            special = 0;
        }
        s[i++] = y + '0';
    } while ((n /= 10) > 0);
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
