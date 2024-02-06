#ifndef _H_DIR_ENT
#define _H_DIR_ENT
#ifndef NAME_MAX
#define NAME_MAX 14	/* Longest filename component; system-dependent */
#endif


typedef struct {		/* portable directory entry: */
    long ino;			/* inode number */
    char name[NAME_MAX+1];	/* name + '\0' terminator */
} Dirent;

typedef struct {		/* minimal DIR: no buffering, etc */
    int fd;			/* file descriptor for directory */
    Dirent d;			/* the directory entry */
} DIREC;			/* similar to FILE */

/* defined in dirops.c */
DIREC *opendir(char *dirname);
Dirent *readdir(DIREC *dfd);
void closedir(DIREC *dfd);
#endif
