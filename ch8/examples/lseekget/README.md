# `lseek` system call

The `lseek` system call is used to set the cursor position in a file:

```c
/*
 * lseek: Sets the position in the file whose descriptor is fd to offset, which is taken relative to origin.
 * origin may be 0, 1, or 2, for beginning of file, current position, and end of file, respectively.
 * Returns new position of the cursor, or -1 on error.
 */
long lseek(int fd, long offset, int origin);
```

The `lseek` system call in this example is used to implement a function `get` that may be used to treat a file
as a large array, albeit with slower access.
