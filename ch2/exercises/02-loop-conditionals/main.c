#include <stdio.h>

#define MAXLEN 1000

int main()
{
    char line[MAXLEN];
    getline(line, MAXLEN);
    printf("%s", line);
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	int j = -1;
	while(j < i) {
	    j = i;
	    if (i < lim-1) {
		c = getchar();
		if (c != EOF) {
		    if (c != '\n') {
			s[i++] = c;
		    }
		}
	    }
	}

	/* Save at least one space for newline character. */
	/*for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;*/
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
