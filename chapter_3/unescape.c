#include <stdio.h>
#include <string.h>

const int BUF_SIZE = 1024;

void unescape(char s[], char t[]);

int main()
{
    char input[BUF_SIZE];
    char output[BUF_SIZE];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < BUF_SIZE - 1) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    unescape(input, output);
    printf("%s\n", output);
    return 0;
}

void unescape(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; i < strlen(s); i++, j++) {
        if (s[i] == '\\') {
            switch (s[++i]) {
            case 'n':
                t[j] = '\n';
                break;
            case 't':
                t[j] = '\t';
                break;
            case 'b':
                t[j] = '\b';
                break;
            case 'f':
                t[j] = '\f';
                break;
            case 'a':
                t[j] = '\a';
                break;
            case 'r':
                t[j] = '\r';
                break;
            case 'v':
                t[j] = '\v';
                break;
            default:
                t[j] = '\\';
                t[++j] = s[i];
                break;
            }
        }
        else {
            t[j] = s[i];
        }
    }
    t[j] = '\0';
}
