# Exercise 8-3

Design and write `_flushbuf`, `fflush`, and `fclose`.

## Solution

I referred to Appendix B1.1 (page 242) to understand what the interface should be:

```c
/* On an output stream, fflush causes any buffered but unwritten data to be written;
 * on an input stream, the effect is undefined. It returns EOF for a write error, and
 * zero otherwise. fflush(NULL) flushes all output streams.
 */
int fflush(FILE *stream)

/* 
 * fclose: flushes any unwritten data for `stream`, discards any unread buffered input,
 * frees any automatically allocated buffer, and then closes the stream. It returns `EOF`
 * if any errors occurred, zero otherwise.
 * /
int fclose(FILE *stream)
```
