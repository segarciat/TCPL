#include <stdio.h>	/* NULL */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* strncpy */
#include <sys/stat.h>	/* struct stat */
#include <fcntl.h>	/* open, O_RDONLY */
#include "syscalls.h"	/* read */
#include "direct.h"	/* struct direct */
#include "dirent.h"	/* typedef Dirent, DIREC */

/* fstat: system call similar to stat system call, but accepts a file descriptor fd instead of a file name */
int fstat(int fd, struct stat *);

/* opendir: open a directory for readdir calls
 * verifies that the file is a directory with fstat, allolcates a directory structure, and records the information.
 * */
DIREC *opendir(char *dirname)
{
    int fd;
    struct stat stbuf;
    DIREC* dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1
     || fstat(fd, &stbuf) == -1
     || (stbuf.st_mode & S_IFMT) != S_IFDIR
     || (dp = (DIREC *) malloc(sizeof(DIREC))) == NULL)
	return NULL;
    dp->fd = fd;
    return dp;
}

/* closedir: close directory opened by opendir */
void closedir(DIREC *dp)
{
    if (dp) {
	close(dp->fd);
	free(dp);
    }
}

/* readdir: read directory entries in sequence */
Dirent *readdir(DIREC *dp)
{
    struct direct dirbuf;	/* local directory structure */
    static Dirent d;		/* return: portable structure */

    /* in Ubuntu, read fails for directory; returns -1
     *
     * Therefore, this limits fsize do not walk the directories as expected.
     * a different system call is needed, like getdents
     * see the README.md for more information
     * */
    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
		== sizeof(dirbuf)) 
    {
        if (dirbuf.d_ino == 0)		/* slot not in use (possibly file was removed */
	    continue;
        d.ino = dirbuf.d_ino;
	strncpy(d.name, dirbuf.d_name, DIRSIZ);
	d.name[DIRSIZ] = '\0';		/* ensure termination */
	return &d;
    }
    return NULL;
}
