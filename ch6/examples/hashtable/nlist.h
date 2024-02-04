#ifndef HNLIST
#define HNLIST
struct nlist {		/* table entry: */
    struct nlist *next;		/* next entry in chain */
    char *name;			/* defined name */
    char *defn;			/* replacement text */
};
#endif
