# 8-7: Storage Allocator

The standard library functions `malloc` and `free` (defined in `<stdlib.h>`) are implemented here by
leveraging the `sbrk` UNIX system call, which is used to request memory from the OS:


```c
char *sbrk(int)
```

It returns `-1` on failure (instead of `NULL`), so it must be casted to a `char *`. According to the book:

"An assumption is made that pointersto different blocks returned y `sbrk` can be meaningfully compared.
This is not guaranteed by the standard, which permits comparisons only within an array. Thus this version
of `malloc` is portable only among machines for which general pointer comparison is meaningful."
