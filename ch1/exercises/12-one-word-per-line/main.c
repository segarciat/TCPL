#include <stdio.h>

#define IN  1	/* Inside a word */
#define OUT 0   /* Outside a word */

/* prints input one word per line */
main()
{
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = OUT;
	    putchar('\n');
	}
	else if (state == OUT) {
	    state = IN;
	    putchar(c);
	} else {
	    putchar(c);
	}
    }
}
