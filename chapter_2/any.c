#include <stdio.h>
#include <string.h>

const int BUF_SIZE = 128;

int any(char s1[], char s2[]);

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

    printf("%d\n", any(input, "peach"));
    return 0;
}

/* return the first location in s1 where any char from s2 occurs, or -1 */
int any(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; k < strlen(s2); k++) {
            // zip through s2 looking for a matching char
            if (s1[i] == s2[k]) {
                return i;
            }
        }
    }
    return -1;
}
