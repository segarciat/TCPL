#include <stdio.h>

main()
{
    int c;
    int blanks = 0;

    while((c = getchar()) != EOF) {
	if (c == ' ') {
	    blanks++;
	} else {
	    if (blanks > 0) {
		/* Display pending blank and reset blank count */
		putchar(' ');
		blanks = 0;
	    }
	    /* Display the current character */
	    putchar(c);

	}
    }
}
