# Exercise 4-7

Write a routine `ungets(s)` that will push back an entire string onto the input. Should `ungets` know about `buf` and
`bufp`, or should it just use `ungetch`?

## Solution

It should just use `ungetch`, treating a string as an array of characters.
