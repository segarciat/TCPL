#ifndef _H_SYSCALLS
#define _H_SYSCALLS
/*
 * (Non-standard) Headers for UNIX syscalls used in Chapter 8
 * 
 */

/* read: returns number of bytes read (may be less than requested. 0 if EOF reached (empty input) and -1 if error */
int read(int fd, char *buf, int n);
/* write: places requested number of bytes in buf, and returns number written. If less than n, that indicates an error. */
int write(int fd, char *buf, int n);
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

/* breaks the connection between a file descriptor and a file */
int close(int fd);
#endif
