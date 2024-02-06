# fsize

There are two implementations here because the book version is specific to Version 7 and System V Unix,
whereas I did these exercises on Ubuntu WSL (version 22). The main issue is that the `read` system call
does not work on directories in Ubuntu, whereas it did in Version 7 and System V. Moreover, Ubuntu houses
in `<system/dir.h>` the appropriate `DIR` and `dirent` structures for representating a directory, and the
functions `opendir`, `readdir`, and `closedir` used by the fsize program. For more details, navigate into
each subdirectory.
