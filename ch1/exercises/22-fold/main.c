#include <stdio.h>
#define FOLD_WIDTH 5 /* number of characters per line */
#define COLUMN_WIDTH 8 /* number of spaces covered by a tab */

int movecursor(int column);

/* folds input lines according to COLUMN_WIDTH */
int main()
{
    int c;

    int column = 0;
    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    int spaces = COLUMN_WIDTH;
	    while (spaces-- > 0) {
		putchar(' ');
		column = movecursor(column);
	    }
        }
	else if (c != '\n') {
	    putchar(c);;
	    column = movecursor(column);
	} else {
	    putchar('\n');
	    column = 0;
	}
    }
}

/* movecursor: computes new column number, outputting new line when reaching column limit
 * 0 <= column < COLUMN_WIDTH
 */
int movecursor(int column)
{
    if (++column == FOLD_WIDTH)
	putchar('\n');
    return column % FOLD_WIDTH;
}
