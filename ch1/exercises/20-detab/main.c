#include <stdio.h>
#define COLUMN_WIDTH 8

int main()
{
    int c;
    int position;

    position = 0;
    while((c = getchar()) != EOF) {
	if (c != '\t') {
	    putchar(c);
	    position = (position + 1) % COLUMN_WIDTH;
	} else {
	    while (position != COLUMN_WIDTH) {
		putchar(' ');
		position = position + 1;
	    }
	    position = 0;
	}
    }
    return 0;
}
