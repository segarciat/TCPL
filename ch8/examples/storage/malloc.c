#include "blockheader.h"
#include "syscall.h"

static Header base;		/* empty list to get started */
static Header *freep = NULL;	/* start of free list */


/* free: put block ap in free list */
void free(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1;	/* point to block header */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
	if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
	    break;	/* freed block at start or end of arena */

    if (bp + bp->s.size == p->s.ptr) {	/* join to upper nbr (neighbor) */
	bp->s.size += p->s.ptr->s.size;
	bp->s.ptr = p->s.ptr->s.ptr;
    } else
	bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) {		/* join to lower nbr */
	p->s.size += bp->s.size;
	p->s.ptr = bp->s.ptr;
    } else
	p->s.ptr = bp;
    freep = p;
}

#define NALLOC 1024     /* minimum #units to request */

void free(void *ap);
/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
    char *cp, *sbrk(int);
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1)      /* no space at all */
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    free((void *)(up+1));
    return freep;
}

/* malloc: general-purpose storage allocator */
void *malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    /* converts to Header-sized block units, and rounds up.
     * verbatim in book: "the requested size in characters is rounded up to the
     * proper number of header-sized units; the block taht will be allocated
     * contains one more unit, for the header itself, and this is the value
     * recorded in the size field of the header"
     */
    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {	/* no free list yet */
	base.s.ptr = freep = prevp = &base;
	base.s.size = 0;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
	if (p->s.size >= nunits) {	/* big enough */
	    if (p->s.size == nunits)	/* exactly */
		prevp->s.ptr = p->s.ptr;
	    else {			/* allocate tail end */
		p->s.size -= nunits;
		p += p->s.size;
		p->s.size = nunits;
	    }
	    freep = prevp;
	    return (void *)(p+1);	/* p is the header, p+1 is the actual memory block, see image on page 186 */
	}
	if (p == freep)	/* wrapped around free list */
	    if ((p = morecore(nunits)) == NULL)
		return NULL;	/* none left */
    }
}

