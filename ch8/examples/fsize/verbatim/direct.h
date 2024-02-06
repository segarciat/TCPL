#include <sys/types.h>	/* typdef ino_t */
#define DIRSIZ 14
/* valid in Version 7 and System V UNIX Systems */
struct direct
{
    ino_t d_ino;		/* inode number */
    char d_name[DIRSIZ];	/* long name does not have '\0' */
};
/* #include <sys/dirent.h> */	/* defines dirent structure similar to above. It also defines DIR */

