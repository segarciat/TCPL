# Exercise 6-2

Write a progrma that reads a C program and prints in alphabetical order each group of variable names that are identical
in the first 6 characters, but different somewhere thereafter. Don't count words within strings and comments. Make 6 a
parameter that can be set from the command line.

## Compiling

```bash
gcc -std=c89 -o printgroups getch.c  getword.c  main.c  tnode.c  vnode.c
```

## Run the program

To run the program, provide an optional numerical argument, and standard input.

```bash
printgroups 4 < main.c
```

## To-do

The program is not fully impleented. It prints groups, in alphabetical order, but it just reds all words in the input, not
specifically variables.
