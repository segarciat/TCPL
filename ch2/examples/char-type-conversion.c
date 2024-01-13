#include <stdio.h>

int atoi(const char s[]);

int main()
{
    const char number[] = "12345";
    printf("String %s converts to integer %d\n", number, atoi(number));
}

int atoi(const char s[])
{
    int i, n;
    
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
	n = 10 * n + (s[i] - '0');
    return n;
}
