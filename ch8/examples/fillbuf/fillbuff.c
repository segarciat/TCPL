#include <stdlib.h>	/* malloc, and since it includes stddef, it actually has NULL too */
#include "syscalls.h"
#include "stdio_excerpt.h"
/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
	return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)	/* no buffer yet */
	if ((fp->base = (char *) malloc(bufsize)) == NULL)
	    return EOF;		/* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
	if (fp->cnt == -1)
	    fp->flag |= _EOF;
	else
	    fp->flag |= _ERR;
    }
    return (unsigned char) *fp->ptr++;
}
