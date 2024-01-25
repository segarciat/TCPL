#include <string.h> /* strcmp */
#include <stdio.h> /* NULL */
#define MAXLEN 1000	/* max length of any input line */

int getline(char *, int);
char *alloc(int);

/* realdines: read input lines and save last 'maxlines' lines, returns pointers to oldest, or NULL if error happens
 *
 * such as a line that is too long
 * */
char **readlines(char *lineptr[], int maxlines)
{
    int len;
    char *p, line[MAXLEN];
    char **next = lineptr;
    lineptr[maxlines - 1] = NULL;

    while ((len = getline(line, MAXLEN)) > 0)
	if ((p = alloc(len)) == NULL)
	    return NULL;
	else {
	    line[len-1] = '\0';	/* delete newline */
	    strcpy(p, line);
	    if (next == lineptr + maxlines)	/* reset back to beginning if reached the end */
		next = lineptr;
	    *next++ = p;	/* save line and move pointer forward */
	}
    if (lineptr[maxlines - 1] == NULL) {
	*next = NULL;
	return lineptr;
    } else if (next == lineptr + maxlines) {
	return lineptr;
    } else {
	return next;
    }
}

/* writelines: prints text stored in lines, starting at oldest and wrapping around if necessary */
void writelines(char **lines, char **oldest, long n)
{
    char **p;
    int i = 0;
    for (p = oldest, i = 0;  i < n && *p != NULL; i++, p++) {
	if (p == lines + n) {
	    p = lines;
	}
	printf("%s\n", *p);
    }
}
