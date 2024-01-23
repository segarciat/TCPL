#include <stdio.h>
#include <stdlib.h> /* atol */
#define COLUMN_WIDTH 8

int validate(int, char**, long[]);

/* detab: converts tabs to the equivalent spaces to reach the next tab stop */
int main(int argc, char *argv[])
{
    long widths[argc - 1];	/* tab stop widths computed from the list of tab stops */

    if (!validate(argc, argv++, widths)) {
	printf("Usage: provide a mononotically increasing list of positive integers, or no arguments at all\n");
	return 1;
    }

    int width_index;		/* index of next tab width to use */
    int c;			/* current character being processed */
    int position;		/* cursor position */
    long tabwidth;		/* width from current tab stop to next one */

    width_index = 0;
    position = 0;
    tabwidth = (argc == 1) ? COLUMN_WIDTH : widths[width_index++];

    while((c = getchar()) != EOF) {
	if (c == '\n') {
	    putchar(c);
	    position = 0;
	    width_index = 0;
	} else if (c == '\t') {
	    while (position != tabwidth) {
		putchar(' ');
		position = position + 1;
	    }
	    position = 0;
	} else {
	    putchar(c);
	    position = (position + 1) % tabwidth;
	}

	if (position == 0)
	    tabwidth = (argc == 1 || width_index == argc - 1) ? COLUMN_WIDTH : widths[width_index++];
    }
    return 0;
}
