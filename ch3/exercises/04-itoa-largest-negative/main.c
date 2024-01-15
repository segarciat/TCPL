#include <stdio.h>
#include <limits.h>
#define LEN 1000

void itoa(int n, char s[]);

int main()
{
    int n = -12345;
    char s[LEN];
    itoa(n, s);
    printf("itoa on %d yields %s\n", n, s);

    itoa(INT_MIN, s);
    printf("itoa on largest negative: %s\n", s);
}

/* reverse: reverses a string in-place */
void reverse(char s[])
{
    int n = 0;
    while(s[n] != '\0')
	n++;

    int c, i, j;
    for (i = 0, j = n - 1; i < j; i++, j--) {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    unsigned int m = (n == INT_MIN)? n: -n;	/* gets rid of signed bit */
    int i = 0;
    int sign = n;
    do {				/* generate digits in reverse order */
	s[i++] = m % 10 + '0';	/* get next digit */
    } while ((m /= 10) > 0);	/* delete it */
    if (sign < 0)
	s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
