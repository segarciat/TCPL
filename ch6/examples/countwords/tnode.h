#ifndef HTNODE
#define HTNODE
struct tnode {		/* the tree node: */
    char *word;		    /* points to the text */
    int count;		    /* nubmer of occurrences */
    struct tnode *left;	    /* left child */
    struct tnode *right;    /* right child */
};
#endif
