# Exercise 6-6

Implmenet a simple version of the `#define` processor (i.e., no arguments) suitable for use with C programs,
based on the routines of this section. You may also find `getch` and `ungetch` helpful.

## Solution

The solution in this exercise assumes that the given source file contains valid C syntax and simple, non-argument
`#define` commands. Moreover, it assumes that each `#define` contains no more than 100 characters. The program
deletes any `#define` statements from the source code, as well as comments. It replaces strings that were provided
as keys to `#define` statements with the associated values.

To compile:

```bash
gcc -o process_defines getch.c  getword.c  main.c  strdup.c  table.cc
```

To run on a sample C file, run it on a C file such as `getch.c`:

```bash
process_defines < getch.c
```
