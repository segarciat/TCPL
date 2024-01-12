#include <stdio.h>
#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
int trim(char s[]);

/* display non-empty lines after removing trailing blanks and tabs */
main()
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = getline(line, MAXLINE)) > 0){
		int newlen = trim(line);
		if (newlen > 1)
			printf("%s", line);
	}
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	/* Save at least one space for newline character. */
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* trim: removes trailing blanks and tabs, and returns length of resulting string */
int trim(char s[])
{
    /* Find the length */
    int len = 0;
    while (s[len] != '\0')
	len++;

    /* Starting at end, delete tabs and blanks until a valid character is reached */
    int i;
    for (i = len - 1; i >=0 && (s[i] == '\t' || s[i] == ' '); i--) {
	s[i] = '\0';
	len--;
    }
    return len;
}
