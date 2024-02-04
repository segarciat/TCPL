#include <stdio.h>	/* printf */
#include <string.h>	/* strcmp */
#include <ctype.h>	/* toupper, tolower */

int main(int argc, char *argv[])
{
    if (--argc != 1 || (strcmp(*++argv, "lower") != 0 && strcmp(*argv, "upper") != 0)) {
	printf("Usage: provide 'lower' or 'upper'\n");
	return 1;
    }

    int c;
    if (strcmp(*argv, "lower") == 0)
	while ((c = getchar()) != EOF)
	    putchar(tolower(c));
    else
	while((c = getchar()) != EOF)
	    putchar(toupper(c));
    return 0;
}
