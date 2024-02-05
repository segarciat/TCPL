#ifndef _H_SYSCALLS
#define _H_SYSCALLS
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

/* close: breaks the connection between a file descriptor and an open file, and frees the file descriptor
 * for use with some other file
 */
int close(int fd);
#endif
