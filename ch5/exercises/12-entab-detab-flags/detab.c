#include <stdio.h>

int read_parameters(char **argv, long *m, long *n);

/* detab: converts tabs to the equivalent spaces to reach the next tab stop */
int main(int argc, char *argv[])
{
    long n, m;
    if (read_parameters(++argv, &m, &n) == -1)	/* error occurred while reading the parameters */
	return 1;

    int c;			/* current character being processed */
    int column;			/* cursor position */
    long tabwidth;		/* width from current tab stop to next one */

    column = 0;
    tabwidth = m;		/* first tab stop is at column m */

    while((c = getchar()) != EOF) {
	if (c == '\n') {
	    putchar(c);
	    column = 0;
	} else if (c == '\t') {
	    while (column++ != tabwidth)
		putchar(' ');
	    column = 0;
	} else {
	    putchar(c);
	    column = (column + 1) % tabwidth;
	}
	if (c == '\n')
	    tabwidth = m;
	else if (column == 0)
	    tabwidth = n;
    }
    return 0;
}
