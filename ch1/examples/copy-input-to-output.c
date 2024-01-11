#include <stdio.h>

/* copy input to output; 1st version */
main()
{
    /* Must be large enough for a value returned by getchar(), all of which fit in a char, except EOF.  */
    int c;

    /* Reads the next input character from a text stream and returns its value */
    c = getchar();
    /* EOF means end of file, an integer defined in <stdio.h> */
    while (c != EOF) {
	/* Prints character c, usually on the screen */
	putchar(c);
	c = getchar();
    }
}
