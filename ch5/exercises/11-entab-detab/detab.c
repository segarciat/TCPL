#include <stdio.h>
#include <stdlib.h> /* atol */
#define COLUMN_WIDTH 8

int validate(int, char**);
long handle_tabstop(long*, char*);
char** reset(int *position, long *prevstop, long *tabwidth, char **tab_stop_list_start);

/* detab: converts tabs to the equivalent spaces to reach the next tab stop */
int main(int argc, char *argv[])
{
    if (!validate(argc, argv++)) {
	printf("Usage: provide a mononotically increasing list of positive integers, or no arguments at all\n");
	return 1;
    }

    int c;				/* current character read */
    int  position;			/* current cursor position */
    long tabwidth;			/* width of current tab stop */
    long prevstop;			/* position of previous tab stop */
    char **argvstart = argv;		/* pointer to position of first command-line argument, if any was provided */

    argv = reset(&position, &prevstop, &tabwidth, argvstart);

    while((c = getchar()) != EOF) {
	if (c == '\n') {
	    putchar(c);
	    argv = reset(&position, &prevstop, &tabwidth, argvstart);
	} else if (c == '\t') {
	    while (position != tabwidth) {
		putchar(' ');
		position = position + 1;
	    }
	    position = 0;
	    tabwidth = (argv == NULL) ? COLUMN_WIDTH: handle_tabstop(&prevstop, *argv++);
	} else {
	    putchar(c);
	    position = (position + 1) % tabwidth;
	    if (position == 0)
	    	tabwidth = (argv == NULL) ? COLUMN_WIDTH: handle_tabstop(&prevstop, *argv++);
	}
    }
    return 0;
}

/* handle_tabstop: updates value of prevstop to be the value of nextstop and returns new tabwidth value */
long handle_tabstop(long *prevstop, char *nextstop)
{
    long newstop = atol(nextstop);
    long tabwidth = newstop - *prevstop;
    *prevstop = newstop;
    return tabwidth;
}

/* reset: sets cursor position, value of prevtabstop, and tabwidth to initial values
 * returns the next position in tab stop list
 *
 * */
char** reset(int *position, long *prevstop, long *tabwidth, char **tab_stop_list_start)
{
    *position = 0;
    if (*tab_stop_list_start == NULL) {
	*tabwidth = COLUMN_WIDTH;
	return NULL;
    } else {
	*tabwidth = *prevstop = atol(*tab_stop_list_start);
	return tab_stop_list_start + 1;
    }
}
