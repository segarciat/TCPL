#include <stdio.h> /* EOF */
#include <ctype.h> /* isspace, isalnum, isalpha */

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()) && c != '\n')    /* skip white space */
	;
    if (c != EOF)
	*w++ = c;
    if (!isalpha(c)) {
	*w= '\0';
	return c;
    }
    for ( ; --lim > 0; w++)
	if (!isalnum(*w = getch())) {
	    ungetch(*w);
	    break;
	}
    *w = '\0';
    return word[0];
}
