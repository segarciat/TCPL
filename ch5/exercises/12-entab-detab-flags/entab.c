#include <stdio.h>

int read_parameters(char **argv, long *m, long *n);

/* replace all spaces in input with tabs needed to reach tab stop, preferring blank when one blank away from tab stop */
int main(int argc, char *argv[])
{
    long m, n;
    if (read_parameters(++argv, &m, &n) == -1)	/* failure while reading parameters */
	return 1;

    int c;		/* current character being processed */
    int tabwidth;	/* current tab stop width */

    tabwidth = m;	/* first tab has size m */

    int blanks = 0;
    int column = 0;
    while ((c = getchar()) != EOF) {
	if (c != ' ') { /* Display pending blanks */
	    for (; blanks > 0; blanks--)
		putchar(' ');
	    putchar(c);
	} else if (column == tabwidth - 1) { /* Reached tab stop with blank */
	    /* Prefer blank over single-space tab */
	    putchar((++blanks == 1)? ' ': '\t');
	    blanks = 0;
	} else
	    blanks++;

	column = (c == '\n') ? 0: (column + 1) % tabwidth;
	if (c == '\n')
	    tabwidth = m;
	else if (column == 0)
	    tabwidth = n;
    }
}
