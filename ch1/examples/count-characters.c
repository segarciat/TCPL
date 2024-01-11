#include <stdio.h>

/* count characters in input; 1st version */
main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
	++nc;
    /* ld to print a long integer. long integers are at least 32 bits. */
    printf("%ld\n", nc);
}
