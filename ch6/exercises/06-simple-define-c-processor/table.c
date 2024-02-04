#include <stdio.h>	/* NULL */
#include <string.h>	/* strcmp */
#include <stdlib.h>	/* malloc, free */
#include "nlist.h"

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];	/* pointer table */

/* hash: form hash value from string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
	hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	if (strcmp(s, np->name) == 0)
	    return np;	/* found */
    return NULL;	/* not found */
}

struct nlist *lookup(char *);
char *strdup_(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {	/* not found */
	np = (struct nlist *) malloc(sizeof(*np));	/* although np is NULL, sizeof(*np) is legal */
	if (np == NULL || (np->name = strdup_(name)) == NULL)
	    return NULL;
	hashval = hash(name);
	np->next = hashtab[hashval];
	hashtab[hashval] = np;
    } else
	free((void *) np->defn);  /* free previous defn */
    if ((np->defn = strdup_(defn)) == NULL)
	return NULL;
    return np;
}

/* undef: remove name and definition from table */
void undef(char *name)
{
    struct nlist *np, *prev;
    unsigned hashval;

    hashval = hash(name);
    prev = NULL;
    for (np = hashtab[hashval]; np != NULL && strcmp(np->name, name) != 0; prev = np, np = np->next)
	;
    if (np != NULL) {		/* found */
	if (prev == NULL)	/* first entry in hash table */
	    hashtab[hashval] = np->next;
	else
	    prev->next = np->next;	/* entry past the first; remove from list */
	free((void *) np->name);	/* free memory for np and its components */
	free((void *) np->defn);
	free((void *) np);
    }
}
