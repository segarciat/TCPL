# Exercise 8-2

Rewrite `fopen` and `_fillbuf` with fields instead of explicit bit operations. Compare code size and execution speed.

## Solution

To complete, I edited `stdio_excerpt.h`. Specifically, I defined a bit field struct type called `FFlags`.
Then, I changed the type of `flag` in the `_iobuf` (`FILE`) struct from `int` to `FFlags`. Then I commented out
the `_flags` enum. Finally I simply modified the implementations of `fopen` and `_fillbuf` to use this field flag instead.
