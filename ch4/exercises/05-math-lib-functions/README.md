# Exercise 4-5

Add access to library functions like `sin`, `exp`, and `pow`. See `<math.h>` in Appendix B, Section 4.

## Solution

For this exercise, I use the `fmod` function in `<math.h>`. When trying to compile, the following error is issued:

```
/usr/bin/ld: /tmp/cceKBuH7.o: in function `main':
main.c:(.text+0x21): undefined reference to `fmod'
collect2: error: ld returned 1 exit status
```

The problem is that the linker cannot find the module `fmod`. We need to use the `-lm` option to link `libm`, which
contains all the floating point math routines, including `fmod`:

```bash
# Order matters; gcc -lm main.c fails
gcc main.c -lm
```

To compile all files in this folder, I ran:

```bash
gcc main.c -lm getop.c getch.c stack.c
```
