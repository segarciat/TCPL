# 8.6: fsize

The `fsize` program is similar to `ls`, but in addition to listing the file names, it also lists
the size. Its application leverages the `stat` system call, provided in `"syscalls.h":

```c
int stat(char *, struct stat *);
```

Much like a typdef `FILE` exists to interact with files, a `DIR` exists to interact with directories.
The challenge is providing a relatively system-independent way to do something that is highly system depedent.

The `dirent.h` file houses `Dirent.h`, meant to be a portable structure consisting of a file's
`name`, and an `inode`, the index into the inode list maintained by the OS with information about the file.
Then `DIR` consists of a `Dirent` field and a file descriptor `fd`.

The `fsize` program depends on `opendir`, closedir`, and `readdir` to do its work, and their interface
refers to `DIR` and `Dirent` to make it as portable as possible. Their implemntation can be seen in `"dirops.c"`.
However, the actual representation of a directory is highly system dependent; instead of `Dirent`, for example,
the book mentions that for Version 7 and System V UNIX, it actually looks like:

```c
#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct	/* directory entry */
{
    ino_t d_ino;		/* inode number 8/
    char d_name[DIRSIZ];	/* long name does not have '\0' */
};
```

As it stands, the implementation here does not work completely as intended (in my Ubuntu WSL).
The problem is that the implementation is intended for Version 7 and System V Unix, where the
`read` system call works on directories; in Ubuntu, that is not the case, and it returns `-1`.
Therefore, when running the program, there will no directory walk, as intended by the program.

## Compile and Use

Without `dirops.c`, which houses the implementations of `opendir`, `closedir`, `readdir`:


```bash
gcc -o fsize fsize.c
./fsize
``` 

You will see output such as:
```
fsize: can't access ./+�0L+e
fsize: can't access ./'T�[_B!
fsize: can't access ./�`⸮!�(&
fsize: can't access ./�?��?�'
fsize: can't access ./�����(
fsize: can't access ./�txC��9
fsize: can't access ./k{��
fsize: can't access ./�݄�%8mR
fsize: can't access ./���x
fsize: can't access ./�������
    4096 .
```

With `dirops.c`:

```bash
gcc -o fsize fsize.c
./fsize
```

You only see:

```
    4096 .
```

Note that it works on the files, it's just not recursively walking the directory `.` because
of the `read` issue described earlier. Try:

```bash
echo "test" > test.txt
./fsize test.txt
```

You get:

```
       5 test.txt
```

## References

- https://stackoverflow.com/questions/17618472/using-read-system-call-on-a-directory
- https://stackoverflow.com/questions/36144807/why-does-linux-use-getdents-on-directories-instead-of-read
