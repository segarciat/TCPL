#include <stdio.h>

#define MAXLINES 5000		/* max # lines to be sorted */
#define MAXLEN 1000		/* max length of any input line */

char *lineptr[MAXLINES];	/* pointers to text lines */
char lines[MAXLINES * MAXLEN];	/* all characters of all lines */

int readlines(char *lineptr[], int nlines, char *lines, int maxlen);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
main()
{
    int nlines;		/* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES, lines, MAXLEN)) >= 0) {
	qsort(lineptr, 0, nlines-1);
	writelines(lineptr, nlines);
	return 0;
    } else {
        printf("error: input too big to sort\n");
	return 1;
    }
}
