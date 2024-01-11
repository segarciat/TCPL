#include <stdio.h>

#define IN  1	/* Inside a word */
#define OUT 0   /* Outside a word */

/* prints input one word per line */
main()
{
    int c, state, length;

    length = 0;
    state = OUT;
    while((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = OUT;
	    printf(": %d", length);
	    putchar('\n');
	}
	else if (state == OUT) {
	    state = IN;
	    length = 1;
	    putchar(c);
	} else {
	    length++;
	    putchar(c);
	}
    }
}
