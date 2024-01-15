#include <stdio.h>
#include <limits.h>
#define LEN 1000

void itoa(int n, char s[]);

int main()
{
    int n = -12345;
    char s[LEN];
    itoa(n, s);
    printf("%s\n", s);
    printf("largest negative:%d\n", INT_MIN);
    printf("negates to itself:%d\n", -INT_MIN);
    printf("to negate largest negative, subtract 1: %d\n", INT_MIN - 1);

    char t[LEN];
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
    int i, sign;

    i = 0;
    if ((sign = n) < 0) { /* record sign */
	/* make n positive */
	if (n == INT_MIN) {
	    s[i++] = (INT_MAX % 10) + '0' + 1;
	    n = INT_MAX / 10;
	} else {
	    n = -n;
	}
    }
    do {        /* generate digits in reverse order */
	s[i++] = n % 10 + '0';    /* get next digit */
    } while ((n /= 10) > 0);      /* delete it */
    if (sign < 0)
	s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
