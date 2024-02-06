# 8.5: `_fillbuf`

The `_fillbuf` function is used to allocate a buffer to a file that has recently been opened for reading.
If the file has the `_UNBUF` bit on, the buffer size is 1; otherwise, it is `BUFSIZ`.

This buffer is saved in the `base` field of the `FILE` structure (see `stdio_excerpt.h`). Standard library
functions such as `getc` and `putc` interact with the buffer.
