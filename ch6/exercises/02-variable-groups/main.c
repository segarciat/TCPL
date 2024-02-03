#include <stdio.h> 	/* EOF, printf */
#include <string.h>	/* strlen */
#include <stdlib.h> 	/* strtol */
#include "nodeops.h"

#define DEFAULT_PREFIX_LEN 6
#define MAXLEN 100

int PREFIX_LEN;

int readprefixlen(char*);
int getword(char*, int);

/* read in a C program a print groups of variables */
int main(int argc, char* argv[])
{
    if ((PREFIX_LEN = readprefixlen(*++argv)) < 0) {
	printf("Error: provide a positive integer less than %d\n", MAXLEN);
	return 1;
    }

    char word[MAXLEN];
    struct tnode *root;		/* tree of all variable groups */
    root = NULL;
    while (getword(word, MAXLEN) != EOF) {
	if (strlen(word) < PREFIX_LEN)
	    continue;
	struct vnode* vgroup = findvnode(root, word);
	vgroup = addvnode(vgroup, word);
	root = addtnode(root, vgroup);
    }
    printtree(root, (void (*)(void*))printvgroup);
}

/* readprefixlen: reads a number between positive integer smaller than MAXWORD and returns it, or -1 if invalid */
int readprefixlen(char *arg)
{
    static int BASE = 10;
    char* endp;

    if (arg == NULL)
	return DEFAULT_PREFIX_LEN;

    int len = (int) strtol(arg, &endp, BASE);
    if (*endp != '\0' || len <= 0 || len > MAXLEN)
	return -1;
    return len;
}
