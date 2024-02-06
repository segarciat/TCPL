# cp

This example demonstrates a simplified version of the UNIX program `cp`, which copies on file to another.
It only copies one file, does not permit the second argument to be a directory, and invents permissions instead
of copying them. Uses the system calls `read` and `write, declared in `"syscalls.h"`. It also leverages
the system calls `open` and `creat` [sic], which are available through `<fcntl.h>`, and flags such as
`O_RDONLY`, `O_WRONLY`, and `O_RDWR` that may be provided to the second argument of `open`.

## Compile and Usage

Compile as follows:

```bash
# Use name mycp so as to avoid clobbering the cp command name normally available.
gcc -std=c89 -o mycp main.c error.c
```

Test it out by creating a dummy file and applying the command to it:

```bash
echo "hello" > hello.txt
./mycp hello.txt greeting.txt
cat greeting.txt
```
