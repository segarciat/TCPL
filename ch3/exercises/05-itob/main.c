#include <stdio.h>
#include <limits.h>
#define LEN 1000
#define HEXADECIMAL 16

void itob(int n, char s[], int b);

int main()
{
    int n = -12345;
    char s[LEN];
    int base = HEXADECIMAL;
    itob(n, s, base);
    printf("itoa on %d yields in base %d: %s\n", n, base, s);

    itob(INT_MIN, s, HEXADECIMAL);
    printf("itoa on largest negative in base %d yields: %s\n", base, s);
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

/* itob: convert n into a base b character representation in the string s  */
void itob(int n, char s[], int b)
{
    unsigned int m = (n == INT_MIN) ? n: -n;	/* gets rid of signed bit */
    int i = 0;
    do {				/* generate digits in reverse order */
	int d = m % b; 			/* get next digit */
	if (b == HEXADECIMAL && d >= 10)
	    s[i++] = 'A' + (d - 10);
	else
	    s[i++] = d + '0';
    } while ((m /= b) > 0);	/* delete it */
    if (n < 0)
	s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
