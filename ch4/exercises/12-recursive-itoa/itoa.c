#include <stdio.h>
#define LEN 1000

int itoa(int n, char s[]);

int main()
{
    int n = -12345;
    char s[LEN];
    itoa(n, s);
    printf("%s\n", s);
}

/* itoa: convert n to characters in s */
int itoa(int n, char s[])
{
    int i, sign;

    i = 0;
    if ((sign = n) < 0){ /* record sign */
	n = -n;         /* make n positive */
	s[0] = '-';
    }
    if (n / 10)
	i = itoa(n / 10, s);
    else if (s[i] == '-')
	i++;

    s[i++] = n % 10 + '0';
    s[i] = '\0';
    return i;
}
