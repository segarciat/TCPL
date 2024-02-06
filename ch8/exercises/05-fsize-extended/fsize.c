#include <stdio.h>	/* fprintf, sprintf, stderr, printf, NULL */
#include <string.h>	/* strcmp, strlen */
#include <sys/types.h>	/* typedefs such as dev_t, ino_t, which are part of the stat struct */
#include <sys/stat.h>	/* structure returned by stat: stat syscall, struct stat, flag constants
			   such as S_IFMT, S_IFDIR, etc... */
#include <sys/dir.h>	/* opendir, readdir, closedir, direct, DIR */

void fsize(char *);

/* print file sizes */
int main(int argc, char **argv)
{
    if (argc == 1)	/* default: current directory */
	fsize(".");
    else
	while (--argc > 0)
	    fsize(*++argv);
    return 0;
}



void dirwalk(char *dir, void (*fcn)(char *));
/* fsize: print size of file "name" */
void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
	fprintf(stderr, "fsize: can't access %s\n", name);
	return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
	dirwalk(name, fsize);
    printf("size: %8ld mode: %u nlinks: %lu %s\n",
	   stbuf.st_size, stbuf.st_mode, stbuf.st_nlink, name);
}

#define MAX_PATH 1024
/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;	 /* in <dirent.h>: uses d_name and d_ino instead of name and inode as Dirent does */
    DIR *dfd;		 /* in <dirent.h> */

    if ((dfd = opendir(dir)) == NULL) {
	fprintf(stderr, "dirwalk: can't open %s\n", dir);
	return;
    }
    while ((dp = readdir(dfd)) != NULL) {
	if (strcmp(dp->d_name, ".") == 0
	 || strcmp(dp->d_name, "..") == 0)
	    continue;	/* skip self and parent */
	if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
	    fprintf(stderr, "dirwalk: name %s/%s too long\n",
	        dir, dp->d_name);
	else {
	    sprintf(name, "%s/%s", dir, dp->d_name);
	    (*fcn)(name);
	}
    }
    closedir(dfd);
}
