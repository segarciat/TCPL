# Exercise 4-4

Add commands to print the top element of the stack without popping, to dupicate it, and to swap the top two
elements. Add a command to clear the stack.

## Solution

For this exercise, I use the `fmod` function in `<math.h>`. When trying to compile, the following error is issued:

```
/usr/bin/ld: /tmp/cceKBuH7.o: in function `main':
reverse-polish-calc.c:(.text+0x21): undefined reference to `fmod'
collect2: error: ld returned 1 exit status
```

The problem is that the linker cannot find the module `fmod`. We need to use the `-lm` option to link `libm`, which
contains all the floating point math routines, including `fmod`:

```bash
# Order matters; gcc -lm reverse-polish-calc.c fails
gcc reverse-polish-calc.c -lm
```
