#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max # lines to be sorted */
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int reversed, int fold, int directory,
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
    int directory = 0;	/* 1 if directory order */
    while (argc > 1 && *(argv[1]) == '-') {
	int c;
	while (c = *++argv[1])
	    switch(c) {
		case 'n':
		    numeric = 1;
		    break;
		case 'r':
		    reversed = -1;
		    break;
		case 'f':
		    fold = 1;
		    break;
		case 'd':
		    directory = 1;
		    break;
		default:
		    printf("Invalid option: %c\n", c);
		    return 1;
	    }
	argv++, argc--;
    }
    printf("numeric=%d, reversed=%d, fold=%d, directory=%d\n", numeric, reversed, fold, directory);
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
	qsort((void **) lineptr, 0, nlines-1, reversed, fold, directory,
	  (int (*)(void*, void*))(numeric) ? numcmp: strcmpf);
	writelines(lineptr, nlines);
	return 0;
    } else {
        printf("error: input too big to sort\n");
	return 1;
    }
}
