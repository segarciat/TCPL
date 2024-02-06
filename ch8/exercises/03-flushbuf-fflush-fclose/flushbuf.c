#include <stdlib.h>	/* free */
#include "syscalls.h"	/* FILE, _READ, _WRITE, _EOF, _ERR, EOF, write, NULL */

/* _flushbuf: when fp is open for write, it writes all buffered data, the given character,
 * and deallocates the memory assigned to the buffer. Returns number of bytes written, or
 * EOF if an error occurred. When c is EOF, it skips writing it, and it is not an error.
 * */
int _flushbuf(int c, FILE *fp)
{
    int written = 0;
    unsigned char d = (unsigned char) c;
    if ((fp->flag&(_READ|_WRITE|_EOF|_ERR)) != _WRITE)
	return EOF;
    if (fp->cnt > 0)
    	written += write(fp->fd, fp->ptr, fp->cnt);
    if (c != EOF)
	written += write(fp->fd, &d, 1);
    if (written < 0) {
	fp->flag |= _ERR;
	return EOF;
    }
    free(fp->base);
    fp->ptr = fp->base = NULL;
    fp->cnt = 0;
    return written + 1;
}
