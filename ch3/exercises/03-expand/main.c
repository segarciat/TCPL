#include <stdio.h>
#include <ctype.h> /* isspace */

enum boolean { FALSE, TRUE };

void expand(const char s1[], char s2[]);
void test(const char s1[], char s2[]);

int main()
{
    char expanded[1000];
    test("A-Z", expanded);
    test("a-z", expanded);
    test("0-9", expanded);
    test("a-b-c", expanded);
    test("a-z0-9", expanded);
    test("-a-z", expanded);
    test("a1234", expanded);
    test("a-cx-zp04-6-", expanded);

}

void test(const char shorthand[], char expanded[])
{
    expand(shorthand, expanded);
    printf("%s expands to %s\n", shorthand, expanded);
}

/* expand: expand shorthand expression s1 into expanded expression.
 * e.g. b-e1-4 expands to bcde1234
 * e.g. -a- expands to -a-
 * e.g. a-b-c expands to abc
 * Note: Leading and trailing - are taken literally.
 * Assumptions: input expression stored in s1 is valid, and there is enough space in s2
 * */
void expand(const char s1[], char s2[])
{
    char c;
    int i, j;
    enum boolean expanding;

    i = j = 0;

    for (i = 0; isspace(s1[i]); i++) /* skip whitespace */
	;

    /* leading - taken literally */
    if (s1[i] == '-') {
	s2[j++] = '-';
	i++;
    }

    expanding = FALSE;
    /* allow - character, either case letter and digits */
    for (;s1[i] != '\0'; i++) {
	/* a-b- a-b-c-*/
	if (s1[i] == '-') {
	    expanding = TRUE;
	} else if (!expanding) {
	    s2[j++] = s1[i];
	} else {
	    for (c = s2[j-1] + 1; c <= s1[i]; c++)
		s2[j++] = c;
	    expanding = FALSE;
	}
    }
    
    /* trailing - taken literally */
    if (expanding) {
	s2[j++] = '-';
    }

    s2[j] = '\0'; /* terminate s2 */
}
