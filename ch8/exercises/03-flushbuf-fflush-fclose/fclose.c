#include <stdlib.h>	/* free */
#include "syscalls.h"

/*
 * fclose: flushes any unwritten data for `stream`, discards any unread buffered input,
 * frees any automatically allocated buffer, and then closes the stream. It returns `EOF`
 * if any errors occurred, zero otherwise.
 */
int fclose(FILE *stream)
{
    int closed, written = 0;
    if (stream == NULL)
	return EOF;
    if ((stream->flag& (_READ | _WRITE)) == 0)
	return EOF;		/* file is not open for read or write */
    if (stream->flag & _WRITE)
        written = _flushbuf(EOF, stream);
    free(stream->base);
    closed = close(stream->fd);
    return (written == EOF || closed == -1) ? EOF: 0; 
}
