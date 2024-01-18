# Exercise 4-9

Our `getch` and `ungetch` do not handle a pushed back `EOF` correctly. Decide what their properties ought to be if an `EOF` is pushed back, the implement your design.

## Solution

An `EOF` signals that no more input is present. The reason we would push back input is if we were trying to read ahead
to make a correct interpretation about the input being parsed. The input is placed back so that the next parsing routine
can make its own decisions about the input. `EOF` should not be pushed back to begin with. The `getch` and `ungetch`
pair should handle it as follows:

1. If `ungetch` receives `EOF`, no operation is done, regardless of the buffer size.
2. `getch` will continue to work as usual, with the assumption that the buffer will never have `EOF`.
