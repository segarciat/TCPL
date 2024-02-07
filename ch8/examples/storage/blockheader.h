#ifndef _H_STORAGE_BLOCK_HEADER
#define _H_STORAGE_BLOCK_HEADER
typedef long Align;	/* for alignment to long boundary */

union header {		/* block header: */
    struct {
	union header *ptr;	/* next block if on free list */
	unsigned size;		/* size of this block */
    } s;
    Align x;		/* force alignment of blocks; never used */
};

typedef union header Header;
#endif
