# Exercise 5-10

Write a program `expr`, which evaluates a reverse Polish expression from the command line, where each operator or operand
is a separate argument. For example:

```bash
expr 2 3 4 + *
```

## Solution

Compile:

```bash
gcc -std=c89 -o expr main.c stack.c
```

Since `*` is a glob character, it is expanded by the terminal, so it needs to be escaped:

```bash
./expr 2 3 4 + \*
```
