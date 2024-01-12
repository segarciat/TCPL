#include <stdio.h>
#define MAXLINE		5	/* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the beginning of the longest line, and its length */
main()
{
	int len;			/* current line length */
	int inputlen;			/* length reported by getline */
	int max;			/* maximum length seen so far */
	char input[MAXLINE];		/* current input read by getline */
	char linestart[MAXLINE];	/* current line, possibly split across getline calls */
	char longest[MAXLINE];		/* longest line saved here */

	len = 0;
	max = 0;
	while ((inputlen = getline(input, MAXLINE)) > 0){
		len += inputlen;
		if (len < MAXLINE)
			copy(linestart, input);
		if (len > max && input[inputlen-1] == '\n') {
			max = len;
			copy(longest, linestart);
			len = 0;
		}
	}
	if (max > 0)		/* there was a line */
		printf("\n%s\n%d\n", longest, max);
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


/* copy: copy 'from' into 'to'; assume 'to' is big enough*/
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
