#include <stdlib.h> /* defines malloc */
#include <string.h> /* strcmp */
#include "tnode.h"  /* talloc */

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_(char *s)	/* make a duplicate of s */
{
    char *p;

    /* malloc returns NULL if no space is available */
    p = (char *) malloc(strlen(s)+1);	/* +1 for '\0' */
    if (p != NULL)
	strcpy(p, s);
    return p;
}
