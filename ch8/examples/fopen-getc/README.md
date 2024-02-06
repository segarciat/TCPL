# 8.5: `fopen` and `getc`

This example shows an implementation of `fopen` and `getc` from `<stdio.h>`. The implementation of `getc` is available
in `stdio_excerpt.h`. Here, constants are defined such as `NULL`, `EOF`, `BUFSIZ` (max buffer size when buffering io),
and `OPEN_MAX` (maximum number of files open by a program simultaneously). It also provides the `FILE` typedef, the
`stdin`, `stdout`, and `stderr` files, a `flags` enum for file status/mode.

Finally, it defines a few functions as macros, such as `feof`, `ferror`, `fileno`, `getc`, `put`, `getchar`, and `putchar`.
