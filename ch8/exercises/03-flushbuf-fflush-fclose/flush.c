#include "syscalls.h"
#include "stdio_excerpt.h"
#include "iobuffer.h"

/* fflush: On an output stream, causes any buffered but unwritten data to be written;
 * on an input stream, the effect is undefined. It returns EOF for a write error, and
 * zero otherwise */
int fflush(FILE *stream)
{
    if (stream == NULL)
	return EOF;
    int written = _flushbuf(EOF, stream);
    return (written == EOF) ? EOF : 0;
}
