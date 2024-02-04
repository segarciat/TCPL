#ifndef HNODES
#define HNODES
struct xrefnode {
    int line;			/* page number where node was found. */
    struct xrefnode *next;	/* next page */
};

struct tnode {
    char* word;			/* word found in text */
    struct xrefnode *linenode;	/* list of lines where word is found */
    struct tnode *left;		/* left tree child node */
    struct tnode *right;	/* right tree child node */
};
#endif
