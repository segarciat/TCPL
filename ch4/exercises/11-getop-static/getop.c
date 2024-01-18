#include <stdio.h> /* for EOF */
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand (handles negative operands) */
int getop(char s[])
{
    static int c = ' ';
    int i;
    s[0] = c;
    while (c == ' ' || c == '\t')        /* skip white space */
        s[0] = c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
	c = ' ';
        return s[0];               /* not a number */
    }
    i = 0;
    if (isdigit(c))         /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')           /* collect fractional part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    c = ' ';
    return NUMBER;
}

