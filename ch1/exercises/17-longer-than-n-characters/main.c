#include <stdio.h>
#define MAXLINE		1000	/* maximum input line size */
#define LINE_THRESHOLD  5 /* length of shortest line to be displayed */

int getline(char line[], int maxline);

/* print lines longer than LINE_THRESHOLD characters */
main()
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = getline(line, MAXLINE)) > 0){
		if (len > LINE_THRESHOLD) {
			printf("%s", line);
		}
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
