#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "key.h"

extern struct key keytab[];

#define MAXWORD 100
/*
 * Using sizeof operator, we can calculate how many elements are in  the keytab array.
 * sizeof returns an integer value whose type, size_t, is defined in <stddef.h>
 *
 * #define NKEYS (sizeof keytab / sizeif(struct key))
 *
 * The directive below is preferable, since it allows the underlying type of keytab to change.
*/
#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
	if (isalpha(word[0]))
	    if ((n = binsearch(word, keytab, NKEYS)) >= 0)
		keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
	if (keytab[n].count > 0)
	    printf("%4d %s\n",
		keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
	mid = (low+high) / 2;
	if ((cond = strcmp(word, tab[mid].word)) < 0)
	    high = mid - 1;
	else if (cond > 0)
	    low = mid + 1;
	else
	    return mid;
    }
    return -1;
}
