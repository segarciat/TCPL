#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666	/* RW for owner, group, others */

int main()
{
    FILE *fopen(char *name, char* mode);
    FILE *fp = fopen("README.md", "r");
    char ERROR_BUFSZ = 6;
    char errormessage[] = "error\n";
    
    const int INPUT_BUFSIZ = 1024;
    char inbuf[INPUT_BUFSIZ];

    int n = read(fp->fd, inbuf, 5);
    if (n == -1)
	write(1, errormessage, ERROR_BUFSZ);
    else
	write(1, inbuf, n);
    return 0;
}

/* fopen: open file, return file ptr
 * does not recognize "b" that signals binary access, since that is meaningless on UNIX systems
 * does not recognize "+" that permits both reading and writing
 * */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
	return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
	if ((fp->flag & (_READ | _WRITE)) == 0)
	    break;		/* found free slot */
    if (fp >= _iob + OPEN_MAX)	/* no free slots */
	return NULL;

    if (*mode == 'w')
	fd = creat(name, PERMS);
    else if (*mode == 'a') {
	if ((fd = open(name, O_WRONLY, 0)) == -1)
	    fd = creat(name, PERMS);
	lseek(fd, 0L, 2);	/* 2 means move to end of file, and a 0L means 0 offset from that position */
    } else
	fd = open(name, O_RDONLY, 0);
    if (fd == -1)	/* couldn't access name */
	return NULL;
    fp-> fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}
