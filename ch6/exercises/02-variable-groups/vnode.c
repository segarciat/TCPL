#include "node.h"	/* struct vnode */
#include <stdlib.h>	/* malloc */
#include <stddef.h>	/* size_t */
#include <string.h>	/* strlen, strcpy */
#include <stdio.h>	/* NULL, printf */

extern int PREFIX_LEN;

/* valloc: allocates memory for a vnode object and reeturns a pointer to it */
struct vnode* valloc_(void)
{
    return (struct vnode*) malloc(sizeof(struct vnode));
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

/* addvnode: creates a node for the given variable name if it does not exist, and returns it */
struct vnode* addvnode(struct vnode* p, char* varname)
{
    int cond;
    if (p == NULL) {
        p = valloc_();
        p->v = strdup_(varname);   /* warning: strdup_ may return NULL, and this does not check for that */
        p->left = p->right = NULL;
    } else if ((cond = strcmp(varname + PREFIX_LEN, p->v + PREFIX_LEN)) == 0) {
        ;       /* do nothing */
    } else if (cond < 0)
        p->left = addvnode(p->left, varname);
    else
        p->right = addvnode(p->right, varname);
    return p;
}

/* printvgroup: prints names of variables in the group in alphabetical order */
void printvgroup(struct vnode* vtree)
{
    if (vtree != NULL) {
        printvgroup(vtree->left);
        printf("%s ", vtree->v);
        printvgroup(vtree->right);
    }
}
