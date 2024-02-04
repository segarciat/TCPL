#include <stdio.h> 	/* NULL */
#include <stdlib.h> 	/* malloc */
#include <string.h>	/* strlen, strcmp */
#include "structs.h"

/* wtree: allocates sufficient memory for a wtree object */
struct wtree* wtalloc(void)
{
    return (struct wtree*) malloc(sizeof(struct wtree));
}

struct wordlist* wlalloc(void)
{
    return (struct wordlist*) malloc(sizeof(struct wordlist));
}

struct ftree* ftalloc(void)
{
    return (struct ftree*) malloc(sizeof(struct ftree));
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


/* addwtnode: updates the frequency on the node matching word, or create  new node if none match */
struct wtree* addwtnode(struct wtree* tree, char* word)
{
    int cond;
    if (tree == NULL) {
	tree = wtalloc();
	tree->word = strdup_(word);
	tree->frequency = 1;
	tree->left = tree->right = NULL;
    } else if ((cond = strcmp(word, tree->word)) == 0) {
	tree->frequency++;
    } else if (cond < 0)
	tree->left = addwtnode(tree->left, word);
    else
	tree->right = addwtnode(tree->right, word);
    return tree;
}

/* addftnode: adds */
struct ftree* addftnode(struct ftree* fnode, struct wtree* wtnode)
{
    int cond;
    if (fnode == NULL) {
	struct wordlist *wnode = wlalloc();
	wnode->word = wtnode->word;
	wnode->next = NULL;

	fnode = ftalloc();
	fnode->frequency = wtnode->frequency;
	fnode->first = wnode;

	fnode->left = fnode->right = NULL;
    } else if ((cond = wtnode->frequency - fnode->frequency) == 0) {
	struct wordlist *wnode = wlalloc();
	wnode->word = wtnode->word;
	wnode->next = fnode->first;

	fnode->first = wnode;
    } else if (cond < 0) {
	fnode->left = addftnode(fnode->left, wtnode);
    } else {
	fnode->right = addftnode(fnode->right, wtnode);
    }
    return fnode;
}

struct ftree *make_ftree(struct ftree* fnode, struct wtree* wtnode)
{
    if (wtnode != NULL) {
        fnode = make_ftree(fnode, wtnode->left);
	fnode = addftnode(fnode, wtnode);
	fnode = make_ftree(fnode, wtnode->right);
    }
    return fnode;
}
