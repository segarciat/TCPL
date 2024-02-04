#include <stdlib.h>	/* malloc */
#include <stdio.h>	/* NULL */
#include <string.h>	/* strcpy, strlen */

char *strdup_(char *s)  /* make a duplicate of s */
{
    char *p;

    /* malloc returns NULL if no space is available */
    p = (char *) malloc(strlen(s)+1);   /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}
