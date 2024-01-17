#include <stdio.h> /* for EOF */
#include <ctype.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand (handles negative operands) */
int getop(char s[])
{
	int i, c, d;
	while ((s[0] = c = getch()) == ' ' || c == '\t')	/* skip white space */
			;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.') {
		if (c == '-') {
			d = getch();
			if (isdigit(d) || d == '.')
				s[++i] = c = d;
			else
				ungetch(d);
		}
		if (s[1] == '\0')
			return c;		/* not a number */
	}
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
