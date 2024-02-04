#ifndef HNODEOPS
#define HNODEOPS
#include "structs.h"
struct wtree* addwtnode(struct wtree* wtnode, char* word);
struct ftree *make_ftree(struct ftree* fnode, struct wtree* wtnode);
#endif
