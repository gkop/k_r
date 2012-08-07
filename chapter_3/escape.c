#include <stdio.h>
#include <string.h>

const int BUF_SIZE = 1024;

void escape(char s[], char t[]);

int main()
{
    char input[BUF_SIZE];
    char output[BUF_SIZE*2];
    char c;
    int i = 0;

    while ((c = getchar()) != EOF && i < BUF_SIZE - 1) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';

    escape(input, output);
    printf("%s\n", output);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; i < strlen(s); i++, j++) {
        switch (s[i]) {
        case '\n':
            t[j] = '\\';
            t[++j] = 'n';
            break;
        case '\t':
            t[j] = '\\';
            t[++j] = 't';
            break;
        case '\b':
            t[j] = '\\';
            t[++j] = 'b';
            break;
        case '\f':
            t[j] = '\\';
            t[++j] = 'f';
            break;
        case '\a':
            t[j] = '\\';
            t[++j] = 'a';
            break;
        case '\r':
            t[j] = '\\';
            t[++j] = 'r';
            break;
        case '\v':
            t[j] = '\\';
            t[++j] = 'v';
            break;
        default:
            t[j] = s[i];
            break;
        }
    }
    t[j] = '\0';
}
