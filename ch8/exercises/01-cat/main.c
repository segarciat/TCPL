#include <stdio.h>	/* stdout, ferror */
#include <stdlib.h>	/* exit */
#include <fcntl.h>	/* open, O_RDONLY */
#include "syscalls.h"	/* BUFSIZ, read, write, close */

#define FD_STDIN 0
#define FD_STDOUT 1

void error(char *fmt, ...);

/* cat: concatenate files, version 2 */
int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int, int);
    char *prog = argv[0];	/* program name for errors */

    if (argc == 1) /* no args: copy standard input */
	filecopy(FD_STDIN, FD_STDOUT);
    else
	while (--argc > 0)
	    if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {	/* perms is alawys 0 for open in exercises */
		error("%s: can't open %s", prog, *argv);
	    } else {
		filecopy(fd, FD_STDOUT);
		close(fd);
	    }
    if (ferror(stdout)) /* returns nonzero if an error occurred on the stream passed in */
	error("%s: error writing stdout\n", prog);
    exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int ifd, int ofd)
{
    static char buf[BUFSIZ];

    int n;
    while ((n = read(ifd, buf, BUFSIZ)) > 0)
	write(ofd, buf, n);
}
