# TCPL - The C Programming Language

Repository with examples, as well as exercises from the 2nd edition book by Ritchie and Kernighan.

## Installing C Compiler

To compile a C program on GNU/Linux, you can use `gcc`, the GNU C Compiler. On Ubuntu, you can install `gcc` standalone,
but it is preferable to install `build-essential`:

```bash
# On Ubuntu
sudo apt-get update
sudo apt-get install build-essential
```

By installing `build-essential`, you also install:

* `libc6-dev`: The header files for GNU C Library (`glibc`).
* `gcc`: The GNU C Compiler.
* `g++`: The GNU C++ Compiler.
* `make`: Build tool for medium-large software package.
* `dpkg-dev`: Build a package in `.deb` packaging format (used by Debian and Ubuntu).

[Source](https://learnubuntu.com/install-gcc/). For more, information, run: `apt show build-essential`.

## Running Program

The book assumes ANSI C, which at the time of writing is C89. Therefore, to ensure a program `main.c` is compiled correctly, you run `gcc` with the `-std` parameter set to `c89`, like so:

```bash
gcc -std=c89 main.c
```

By default, it will produce an executable named `./a.out`. To produce a different value, use the `-o` parameter, and supply a name:

```bash
gcc -std=c89 -o myprogram main.c
ls
# file myprogram should exist
```

