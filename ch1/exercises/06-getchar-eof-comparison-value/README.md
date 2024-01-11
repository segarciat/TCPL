# Exercise 1-6

Verify that the expression getchar() != EOF is 0 or 1.

## Solution

To verify, we do the following:

1. Compile `getchar-eof-comparison-value.c`:

```bash
gcc getchar-eof-comparison-value.c
```

which outputs `a.out`.

2. Run the program

```bash
./a.out
```

and type anything followed by the Enter key, such as `hello`. You will see:

```bash
1
```

3. Run the program again

```bash
./a.out
```

but this time input the keystroke CTRL+D. This time the output is

```bash
0
```
