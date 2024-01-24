#include <stdio.h>		/* printf, NULL */
#include <stdlib.h>		/* strtol */
#define DECIMAL 	10
#define COLUMN_WIDTH 	8	/* default value for parameter +n */


int read_parameters(char **argv, long *m, long *n);

/*
int main(int argc, char *argv[])
{
    long m, n;
    int count = read_parameters(++argv, &m, &n);
    printf("count:  %d\n", count);
}
*/

/* read_parameters: reads and assign -m and +n parameters. Returns how many parameters were read, or -1 if error */
int read_parameters(char **argv, long *m, long *n)
{
    int c;
    int count = 0;
    *m = 0, *n = 0;
    while (*argv != NULL && ((c = (*argv)[0]) == '-' || c == '+' ))
    {
	count++;
	if (c == '-' && *m != 0 || c == '+' && *n != 0) {
	    printf("Error: paramater %s may only be specified once\n", (c == '-') ? "-m": "+n");
	    return -1;
	}
	char *endp;
	long k = strtol(++(argv++[0]), &endp, DECIMAL);
	if (*endp != '\0' || k <= 0) {
	    printf("Error: either got a non-positive integer, or encountered invalid number at: %s\n", endp);
	    return -1;
	}
	if (c == '-')
	    *m = k;
	else
	    *n = k;
    }
    if (*n == 0)
	*n = COLUMN_WIDTH;
    if (*m == 0)
	*m = *n;
    return count;
}
