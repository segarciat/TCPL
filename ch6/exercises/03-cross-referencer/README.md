# Exercise 6-3

Write a cross-referencer that prints a list of all words in a document, and, for each word,
a list of the line numbers on which it occurs. Remove noise words like "the", "and", and
so on.

## Compiling

```bash
gcc -std=c89 -o xreference getch.c  getword.c  main.c  noisewords.c  tnode.c
```

## Run the program

To run the program, provide standard input, like so:

```bash
xreference < main.c
```
