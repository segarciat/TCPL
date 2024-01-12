#include <stdio.h>
#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* print longest input line */
main()
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = getline(line, MAXLINE)) > 0){
		reverse(line);
		printf("%s\n", line);
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

/* reverse: reverse the character string s. Assumes s is terminated by \0 */
void reverse(char s[])
{
    /* Determine the length of the string */
    int len = 0;
    while(s[len] != '\0')
	len++;

    /* Reverse it */
    int i;
    int center = len / 2;
    for (i = 0; i < center; i++) {
	char left = s[i];
	s[i] = s[len - 1 - i];
	s[len - 1 - i] = left;
    }
}
