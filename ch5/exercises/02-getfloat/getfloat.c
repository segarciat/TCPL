#include <stdio.h> /* EOF */
#include <ctype.h> /* isspace, isdigit */

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(double *pn)
{
    int c, sign;
    double power;

    while (isspace(c = getch()))        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);     /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? - 1: 1;
    if (c == '+' || c == '-') {
        c = getch();
	if (!isdigit(c) && c != '.') {
	    ungetch(c);
	    return 0;	/* it's not a number */
	}
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
	c = getch();
	if (!isdigit(c)) {
	    ungetch(c);
	    return 0;	/* it's not a number */
	}
    }
    for (power = 1.0; isdigit(c); c = getch()) {
	*pn = 10 * *pn + (c - '0');
	power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
        ungetch(c);
    return c;
}
