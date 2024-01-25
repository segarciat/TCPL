#include <stdio.h>
#include <stdlib.h> /* strtol */
#define DECIMAL 10
#define DEFAULT_COUNT 10
#define MAXLINES 1000

long read_parameter(char **argv);
char **readlines(char **lines, long n);
void writelines(char **lines, char **start, long n);

int main(int argc, char *argv[])
{
    /* read -n parameter, set to default if none provided */
    long n = read_parameter(++argv);
    if (n == -1)	/* error while reading -n parameter */
	return 1;
    else if (n > MAXLINES) {
	printf("Error: maximum value for -n is %d\n", MAXLINES);
	return 1;
    }
    char *lines[n];
    char **first = readlines(lines, n);
    if (first == NULL) {
	printf("input is too large \n");
	return -1;
    } else
	writelines(lines, first, n);
}

/* read_parameter: reads -n parameter from command-line arguments and parses its value, returning -1 if invalid */
long read_parameter(char **argv)
{
    char *endp;
    long n = DEFAULT_COUNT;
    if (*argv != NULL && (*argv)[0] == '-') {
	long k = strtol(++(argv[0]), &endp, DECIMAL);
	if (k <= 0 || *endp != '\0') {
	    printf("Error: either n=%ld is not positive, or encountered invalid number: %s\n", k, endp);
	    return -1;
	}
	n = k;
    }
    return n;
}
