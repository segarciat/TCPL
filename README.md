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
