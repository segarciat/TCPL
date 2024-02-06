#include <stdlib.h>	/* malloc */
#include "syscalls.h"
#include "stdio_excerpt.h"

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if (!fp->flag.read || (fp->flag.err || fp->flag.eof))
	return EOF;
    bufsize = (fp->flag.unbuf) ? 1: BUFSIZ;
    if (fp->base == NULL)	/* no buffer yet */
	if ((fp->base = (char *) malloc(bufsize)) == NULL)
	    return EOF;		/* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
	if (fp->cnt == -1)
	    fp->flag.eof = 1;
	else
	    fp->flag.err = 1;
    }
    return (unsigned char) *fp->ptr++;
}
