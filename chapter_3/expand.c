#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BUF_SIZE = 1024;

void expand(char s1[], char s2[]);

int main()
{
    char input[BUF_SIZE];
    char output[BUF_SIZE*1024];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < BUF_SIZE - 1) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    expand(input, output);
    printf("%s\n", output);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k;
    for (i = 0, j = 0; i < strlen(s1); i++) {
        if (i < strlen(s1) - 2 && s1[i+1] == '-') {
            // found valid bit of shorthand, zip through range, copying
            for (k = s1[i]; k <= s1[i+2]; k++, j++) {
                s2[j] = k;
            }
            // account for having just read dash and end character
            i += 2;
        }
        else {
            // copy character literally
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = '\0';
}
