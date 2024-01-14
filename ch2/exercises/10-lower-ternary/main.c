#include <stdio.h>

int lower(int c);

int main()
{
    char c = 'A';
    printf("%c in lower case is %c\n", c, lower(c));
}

/* lower (version 2): convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c;
}
