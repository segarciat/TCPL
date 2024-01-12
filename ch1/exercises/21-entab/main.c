#include <stdio.h>
#define COLUMN_WIDTH 8

/* replace all spaces in input with tabs needed to reach tab stop, preferring blank when one blank away from tab stop */
int main()
{
    int c;

    int blanks = 0;
    int column = 0;
    while ((c = getchar()) != EOF) {
	if (c != ' ') { /* Display pending blanks */
	    for (; blanks > 0; blanks--)
		putchar(' ');
	    putchar(c);
	} else if (column == COLUMN_WIDTH - 1) { /* Reached tab stop with blank */
	    /* Prefer blank over single-space tab */
	    if (++blanks == 1)
		putchar(' ');
	    else
		putchar('\t');
	    blanks = 0;
	} else {
	    blanks++;
	}

	/* Update column */
	if (c == '\n')
	    column = 0;
	else
	    column = (column + 1) % COLUMN_WIDTH;

    }
}
