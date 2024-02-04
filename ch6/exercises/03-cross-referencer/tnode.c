#include <stdio.h> 	/* NULL */
#include <stdlib.h> 	/* malloc */
#include <string.h>	/* strlen, strcmp */
#include "node.h"

/* talloc: allocates sufficient memory for a tnode object */
struct tnode* talloc(void)
{
    return (struct tnode*) malloc(sizeof(struct tnode));
}

/* mkexrefnode: creates an xrefnode with the given page and returns a pointer to it */
struct xrefnode* makexrefnode(int line)
{
    struct xrefnode* p = (struct xrefnode*) malloc(sizeof(struct xrefnode));
    p->next = NULL;
    p->line = line;
    return p;
}

/* strdup_: creates a string in memory with the same characters as w and returns a pointer to it, or NULL */
char* strdup_(char* w)
{
    size_t len = strlen(w);
    char* p = (char*) malloc(len + 1);
    if (p != NULL) {
        strcpy(p, w);
        p[len] = '\0';
    }
    return p;
}


/* addtnode: adds a tnode with value vgroup */
struct tnode* addtnode(struct tnode* tree, char* word, int line)
{
    int cond;
    if (tree == NULL) {
	tree = talloc();
	tree->word = strdup_(word);
	tree->linenode = makexrefnode(line);
	tree->left = tree->right = NULL;
    } else if ((cond = strcmp(word, tree->word)) == 0) {
	struct xrefnode* lnode = makexrefnode(line);
	lnode->next = tree->linenode; /* add it to the front of the list */
	tree->linenode = lnode;
    } else if (cond < 0)
	tree->left = addtnode(tree->left, word, line);
    else
	tree->right = addtnode(tree->right, word, line);
    return tree;
}
