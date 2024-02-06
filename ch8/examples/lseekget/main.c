#include "syscalls.h"

/* get: read n bytes from position pos
 * Returns number of bytes read, or -1 on error.
 * */
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0)	/* get to pos */
	return read(fd, buf, n);
    else
	return -1;
}
