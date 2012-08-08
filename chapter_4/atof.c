#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

const int BUF_SIZE = 128;

double atof(char s[]);

main()
{
    char input[BUF_SIZE];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < BUF_SIZE - 1) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    printf("%f\n", atof(input));
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, j, sign, exp, exp_sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 *  val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (tolower(s[i++]) == 'e') {
        exp = 0;
        exp_sign = (s[i] == '-') ? -1 : 1;
        for (j=strlen(s)-1; isdigit(s[j]); j--)
            exp += ((s[j] - '0') * pow(10, strlen(s)-j-1));
        return (sign * val / power) * pow(10, exp_sign * exp);
    }
    else
        return sign * val / power;
}
