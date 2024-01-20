#include <stdio.h>

void strcat_(char*, char*);

int main()
{
    char s[50] = {'h', 'e', 'l', 'l', 'o', ',', '\0' };
    strcat_(s, "world\n");
    printf("%s", s);
}
