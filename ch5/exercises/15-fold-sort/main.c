#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max # lines to be sorted */
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int reversed, int fold,
	   int (*comp)(void *, void *));

int numcmp(char *, char*, int);
int strcmpf(char*, char*, int);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;		/* number of input lines read */
    int numeric = 0;	/* 1 if numeric sort */
    int reversed = 1;	/* -1 if reversed */
    int fold = 0;	/* 1 if fold */
    while (argc > 1) {
	if (strcmp(argv[1], "-n") == 0)
	    numeric = 1;
	else if (strcmp(argv[1], "-r") == 0)
	    reversed = -1;
	else if (strcmp(argv[1], "-f") == 0)
	    fold = 1;
	argv++, argc--;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
	qsort((void **) lineptr, 0, nlines-1, reversed, fold,
	  (int (*)(void*, void*))(numeric) ? numcmp: strcmpf);
	writelines(lineptr, nlines);
	return 0;
    } else {
        printf("error: input too big to sort\n");
	return 1;
    }
}
