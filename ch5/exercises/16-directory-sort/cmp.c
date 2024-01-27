#include <stdlib.h>
#include <ctype.h>

int fcmp(char, char, int);


/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2, int fold)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
	return -1;
    else if (v1 > v2)
	return 1;
    else
	return 0;
}

/* strcmpf: compare s1 and s2 lexicographically, ignoring case if fold is set to 1 */
int strcmpf(char *s1, char *s2, int fold, int directory)
{
    while (1) {
	if (fcmp(*s1, *s2, fold) == 0) {
	    if (*s1 == '\0')
		return 0;
	    else
		s1++, s2++;
	} else if (!directory || ((isalnum(*s1) || isspace(*s1)) && (isalnum(*s2) || isspace(*s2)))) {
	    return fcmp(*s1, *s2, fold);
	} else {
	    if (*s1 != '\0' && !isalnum(*s1) && !isspace(*s1))
		s1++;
	    if (*s2 != '\0' && !isalnum(*s2) && !isspace(*s2))
		s2++;
	}
    }
}

int fcmp(char c1, char c2, int fold)
{
    if (fold)
        return tolower(c1) - tolower(c2);
    return c1 - c2;
}
