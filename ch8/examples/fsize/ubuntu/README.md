# 8.6: fsize - Ubuntu

The `fsize` program here is similar to that in `../verbatim`. However, it's specific to my Linux machine.
Instead of `Dirent`, `DIR`, `opendir`, `readdir`, and `closedir, and `direct`, which was homegrown in
`../verbatim` as described in the book for Version 7 and System V UNIX, this uses the `#include <sys/dir.h>`
header, which has the same contents, except that `direct` and `Dirent` are replaced by `dirent`.
