#include <string.h> /* strcmp */
#include <stdio.h> /* NULL */

int getline(char *, int);
char *alloc(int);

/* realdines: read input lines */
int readlines(char *lineptr[], int maxlines, char *lines, int maxlen)
{
    int len, nlines;
    char line[maxlen];

    nlines = 0;
    while ((len = getline(line, maxlen)) > 0)
	if (nlines >= maxlines || (lines >= lines + (maxlines * maxlen)))
	    return -1;
	else {
	    line[len-1] = '\0';	/* delete newline */
	    strcpy(lines, line);
	    lineptr[nlines++] = lines;
	    lines += len;	/* move pointer forward */
	}
    return nlines;
}

/* writelines: write lines to standard output */
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
	printf("%s\n", *lineptr++);
}
