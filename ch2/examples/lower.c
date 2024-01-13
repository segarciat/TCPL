#include <stdio.h>

int lower(int c);

/* <ctype.h> defines a family of functions that provide tests and conversions that are independent of character set
 * for example, it defines tolower(c), an improved version of below.
 * It also has tests like isdigit(c), equivalent to '0' <= c && c <= '9' */
int main()
{
    char c = 'A';
    printf("%c in lowercase is %c\n", c, lower(c));
}

/* convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
	return c + 'a'- 'A';
    else
	return c;
}


