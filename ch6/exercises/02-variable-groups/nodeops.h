#ifndef HNODEOPS
#define HNODEOPS
#include "node.h"
struct vnode* findvnode(struct tnode* p, char *w);
struct tnode* addtnode(struct tnode* tree, struct vnode* vgroup);
void printtree(struct tnode* tree, void (*printgroup)(void*));

struct vnode* addvnode(struct vnode* p, char* varname);
void printvgroup(struct vnode* vtree);
#endif
