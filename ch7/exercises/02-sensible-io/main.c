#include <stdio.h>	/* getchar, putchar */
#include <ctype.h>	/* isgraph */
#define MAXCOLUMN 5

int main()
{
    int c, column, n;

    column = 0;
    while((c = getchar()) != EOF) {
	if (c == '\n')
	    column = 0;
	else if (!isgraph(c) && !isspace(c))
	    column += printf("%x", c);
	else {
	    putchar(c);
	    column++;
	}
	if (column == 0 || column >= MAXCOLUMN)
	    putchar('\n');
	column %= MAXCOLUMN;
    }
}
