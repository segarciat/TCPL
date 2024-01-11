#include <stdio.h>

main()
{
    int blanks, tabs, lines;

    blanks = 0;
    tabs = 0;
    lines = 0;

    int c;
    while ((c = getchar()) != EOF) {
	if (c == ' ')
	    blanks++;
	if (c == '\t')
	    tabs++;
	if (c == '\n')
	    lines++;
    }
    printf("blanks: %d\ntabs: %d\nlines: %d\n", blanks, tabs, lines);
}
