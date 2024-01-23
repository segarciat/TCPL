#include <stdio.h>
#include <stdlib.h> /* strtol */
#define COLUMN_WIDTH 8


int validate(int, char**, long[]);

/* replace all spaces in input with tabs needed to reach tab stop, preferring blank when one blank away from tab stop */
int main(int argc, char *argv[])
{
    long widths[argc - 1];
    if (!validate(argc, argv, widths))
	return 1;

    int width_index;	/* index of the next tab stop width to use */
    int c;		/* current character being processed */
    int tabwidth;	/* current tab stop width */

    width_index = 0;
    tabwidth = (argc == 1)? COLUMN_WIDTH: widths[width_index++];

    int blanks = 0;
    int column = 0;
    while ((c = getchar()) != EOF) {
	if (c != ' ') { /* Display pending blanks */
	    for (; blanks > 0; blanks--)
		putchar(' ');
	    putchar(c);
	    if (c == '\n')
		width_index = 0;
	} else if (column == tabwidth - 1) { /* Reached tab stop with blank */
	    /* Prefer blank over single-space tab */
	    putchar((++blanks == 1)? ' ': '\t');
	    blanks = 0;
	} else
	    blanks++;

	column = (c == '\n') ? 0: (column + 1) % tabwidth;

	if (column == 0)
	    tabwidth = (argc == 1 || width_index == argc - 1) ? COLUMN_WIDTH: widths[width_index++];
    }
}
