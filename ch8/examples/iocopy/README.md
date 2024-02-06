# iocopy

This sample program copies input to output. It demonstrates the usage of UNIX system calls. The following calls are leveraged:

```c
/*
 * read: Reads at most n bytes from a file whose descriptor is fd, and place contents in buf.
 * Returns number of bytes read, or -1 on error.
 */
int read(int fd, char *buf, int n);

/*
 * write: Writes n bytes located in buf into the file whose descriptor is fd.
 * Returns the number of bytes written. If less than n, then an error occured.
 */
int write(int fd, char *buf, int n);
```
