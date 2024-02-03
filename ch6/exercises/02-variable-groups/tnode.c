#include <stdio.h> 	/* NULL */
#include <stdlib.h> 	/* malloc */
#include <string.h>	/* strncmp */
#include "node.h"

extern int PREFIX_LEN;

/* talloc: allocates sufficient memory for a tnode object */
struct tnode* talloc(void)
{
    return (struct tnode*) malloc(sizeof(struct tnode));
}

/* findtnode: finds node containing prefix group that w belongs to, or NULL if no such group exists */
struct vnode* findvnode(struct tnode* p, char *w)
{
    int cond;
    if (p == NULL)
	return NULL;
    else if ((cond = strncmp(w, p->vroot->v, PREFIX_LEN)) == 0)
	return p->vroot;
    else if (cond < 0)
	return findvnode(p->left, w);
    else
	return findvnode(p->right, w);
}

/* addtnode: adds a tnode with value vgroup */
struct tnode* addtnode(struct tnode* tree, struct vnode* vgroup)
{
    int cond;
    if (tree == NULL) {
	tree = talloc();
	tree->vroot = vgroup;
	tree->left = tree->right = NULL;
    } else if ((cond = strncmp(vgroup->v, tree->vroot->v, PREFIX_LEN)) == 0) {
	tree->vroot = vgroup;
    } else if (cond < 0)
	tree->left = addtnode(tree->left, vgroup);
    else
	tree->right = addtnode(tree->right, vgroup);
    return tree;
}

/* printprefix: prints prefix for a given tree node */
void printprefix(struct tnode* node)
{
    int i;
    printf("\n");
    for (i = 0; i < PREFIX_LEN; i++)
	printf("%c", (node->vroot->v)[i]);
    printf(":\n    ");
}

/* printtree: prints all variable groups */
void printtree(struct tnode* tree, void (*printgroup)(void*))
{
    if (tree != NULL) {
	printtree(tree->left, printgroup);
	printprefix(tree);
	(*printgroup)(tree->vroot);
	printf("\n");
	printtree(tree->right, printgroup);
    }
}
