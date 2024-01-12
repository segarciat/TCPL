#include <stdio.h>

#define OUT	0	/* outside string and comment */
#define IN_COMMENT 1
#define IN_STRING  2

int main()
{
    int c, last;

    int state = OUT;
    last = -1;
    while((c = getchar()) != EOF) {
	if (state == IN_COMMENT) {
	    if (last == '*' && c == '/')
		state = OUT;
	} else if (last == '/' && c == '*' && state == OUT) {
	    state = IN_COMMENT;
	} else if (c != '/' || last == '\'') {
	    if (c == '"' && state == OUT)
		state = IN_STRING;
	    else if (c == '"' && last != '\\')
		state = OUT;
	    putchar(c);
	}
	last = c;
    }
}
