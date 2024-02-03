#ifndef HNODES
#define HNODES
struct vnode {
    char *v;			/* variable name */
    struct vnode *left;		/* left child */
    struct vnode *right;	/* right child */
};

struct tnode {
    struct vnode *vroot;	/* root of tree of variable group */
    struct tnode *left;		/* left tree child node */
    struct tnode *right;	/* right tree child node */
};
#endif
