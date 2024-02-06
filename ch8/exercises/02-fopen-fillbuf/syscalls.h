#ifndef _H_SYSCALLS
#define _H_SYSCALLS
#include "stdio_excerpt.h"
#include "iobuffer.h"
/*
 * (Non-standard) Headers for UNIX syscalls used in Chapter 8
 * 
 */
/* read: returns number of bytes read (may be less than requested. 0 if EOF reached (empty input) and -1 if error */
/* BUFSIZ and EOF are given in stdio.h> */
#define BUFSIZ 8192
#define EOF (-1)
/* read: returns number of bytes written. Error if less than n */
int read(int fd, char *buf, int n);
/* write: places requested number of bytes in buf, and returns number written. If less than n, that indicates an error. */
int write(int fd, char *buf, int n);

/* open: opens the file with the indicated name using the given flags. perms is 0 for this chapter's purposes
 * main flag values are: O_RDONLY (open for read and write), O_WRONLY (open for writing only), O_RDWR (open for read and write)
 * the open function is declared in <fcntl.h>
 *
 *
 * int open(char* name, int flags, int perms);
 *
 */

/* close: breaks the connection between a file descriptor and an open file, and frees the file descriptor
 * for use with some other file
 */
int close(int fd);

/* lseek: sets the current position in the file whose descriptor is fd to offset.
 * the position is taken relative to the location specified by origin.
 * subsequent reading will begin at that position.
 * origin can be 0, 1 or 2 to indicate beginning, current, or end of file.
 *
 * returns new position in the file, or -1 if error
 * standard library fseek is similar, except it takes a FILE *, and return is non-zero if error
 *
 * example: to append to a file, seek to the end: lseek(fd, 0L, 2)
 * example: to get back to beginning ("rewind"): lseek(fd, 0L, 0)
 * */
long lseek(int fd, long offset, int origin);
/* creat: creates a file and returns its file descriptor, or -1 if an error occurred
 * if the file already exists, it truncates it to 0 length; not an error to creat a file that already exists.
 *
 * commented out because <fcntl.h> already has an xtern declaration for creat
 * int creat(char *name, int perms);
 */
#endif
