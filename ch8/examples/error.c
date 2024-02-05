#include <stdio.h>	/* fprintf, vfprintf, fprintf */
#include <stdarg.h>	/* va_list, va_start, va_end */
#include <stdlib.h>	/* exit */

/* error: print an error message and die */
void error(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    /* vfprintf: the variable list of argument is replaced by a single argument initialized by calling va_start */
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
