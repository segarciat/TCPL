#include <stdio.h> /* EOF, getchar, putchar */
#include <ctype.h> /* tolower */

/* lower: convert input to lower case */
main()
{
    int c;

    while ((c = getchar()) != EOF)
	putchar(tolower(c));
    return 0;
}
