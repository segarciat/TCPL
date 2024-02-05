#ifndef _H_SYSCALLS
#define _H_SYSCALLS
/*
 * (Non-standard) Headers for UNIX syscalls used in Chapter 8
 * 
 */
/* read: returns number of bytes read (may be less than requested. 0 if EOF reached (empty input) and -1 if error */
#define BUFSIZ 8192
#define EOF (-1)
int read(int fd, char *buf, int n);
/* read: returns number of bytes written. Error if less than n */
int write(int fd, char *buf, int n);
/* BUFSIZ is given in stdio.h> */
#endif
