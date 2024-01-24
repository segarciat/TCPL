# Exercise 5-12

Extend `entab` and `detab` to accept the shorthand

```bash
entab -m +n
```

to mean tab stops every `n` columns, starting at column `m`. Choose convenient (for the user) default behavior.

## Solution

I interpreted the exercise to mean that the first tab stop has width `m`, and that after that, the tab stops have
width `n`. The source file to read the parameters `-m` and `+n` was written separately. To compile the programs, run:

```bash
gcc -std=c89 -o entab entab.c read_parameters.c
gcc -std=c89 -o detab detab.c read_parameters.c
```
