#include <stdio.h>

int customstrlen(char s[]);

int main()
{
    int c;
    printf("The string \"hello world\" has length %d\n", customstrlen("hello world"));
}

/* strlen: return length of s. Use version in <string.h> instead. */
int customstrlen(char s[])
{
    int i;
    
    i = 0;
    while (s[i] != '\0')
	++i;
    return i;
}
