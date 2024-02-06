#include "syscalls.h"
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
/* fseek: sets the file position for stream; a subsequent read or write will access
 * data beginning at the new position. For a binary file, the position is set to
 * offset characters from origin, which may be SEEK_SET (beginning), SEEK_CUR (curent
 * position), or SEEK_END (end of file). For a text stream, offset must be zero, or
 * a value returned by ftell (in which case origin must be SEEK_SET). fseek returns
 * non-zero on error.
 * */
int fseek(FILE *stream, long offset, int origin)
{
    int status;
    if (stream == NULL || (stream->flag & (_READ || _WRITE)))
	return -1;
    if (origin != SEEK_SET && origin != SEEK_CUR && origin != SEEK_END)
	return -1;
    if ((stream->flag & _READ) && stream->cnt > 0) {
	stream->cnt = 0;
	stream->ptr = NULL;
    } else {
	status = _flushbuf(EOF, stream);
    }
    status = 
    lseek(stream->fd, offset, origin);
    return (lseek(stream->fd, offset, origin) < 0 || status == EOF) ? 0 : -1;
}
