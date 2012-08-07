#include <stdio.h>
#include <string.h>

const int BUF_SIZE = 128;

void squeeze(char s1[], char s2[]);

int main()
{
    char input[BUF_SIZE];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < BUF_SIZE - 1) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    squeeze(input, "aeiou");
    printf("%s\n", input);
    return 0;
}

/* delete any char in s1 that matches any char in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; k < strlen(s2); k++) {
            // zip through s2 looking for a matching char
            if (s1[i] == s2[k]) {
                k = -1;
                break;
            }
        }
        if (k >= 0) {
            // no match found, don't delete this char
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
