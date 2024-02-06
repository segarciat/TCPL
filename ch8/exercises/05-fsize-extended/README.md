# Exercise 8-5

Modify the `fsize` program to print the other information contained in the inode entry.

## Solution

This implementation uses the `ch8/example/fsize/ubuntu` as its base. According to the book, the
`stat` system call returns a `struct stat` object, defined in `<sys/stat.h`, and the typedefs are
in `<sys/type.h>`. In the book, where the relevant system is Version 7 and System V UNIX, it looks like:

```c
struct stat	/* inode information returned by stat */
{
    dev_t	st_dev;		/* device of inode */
    ino_t	st_ino;		/* inode number */
    short	st_mode;	/* mode of bits */
    short	st_nlink;	/* number of links to file */
    short	st_uid;		/* owner's user id */
    short	st_gid;		/* owner's group id */
    short	st_rdev;	/* for special files */
    short	st_size;	/* file size in characters */
    short	st_atime;	/* time last accessed */
    short	st_mtime;	/* time last modified */
    short	st_ctime;	/* time inode last changed */
};
```

However, in my Ubuntu WSL, I ran the following command in search of the correct struct:

```bash
find /usr/include/ -name stat.h
```

and got:

```
/usr/include/linux/stat.h
/usr/include/asm-generic/stat.h
/usr/include/x86_64-linux-gnu/sys/stat.h
/usr/include/x86_64-linux-gnu/asm/stat.h
/usr/include/x86_64-linux-gnu/bits/stat.h
```

I found the `struct stat` in `/usr/include/asm-generic/stat.h` to have:

```c
struct stat {
        unsigned long   st_dev;         /* Device.  */
        unsigned long   st_ino;         /* File serial number.  */
        unsigned int    st_mode;        /* File mode.  */
        unsigned int    st_nlink;       /* Link count.  */
        unsigned int    st_uid;         /* User ID of the file's owner.  */
        unsigned int    st_gid;         /* Group ID of the file's group. */
        unsigned long   st_rdev;        /* Device number, if device.  */
        unsigned long   __pad1;
        long            st_size;        /* Size of file, in bytes.  */
        int             st_blksize;     /* Optimal block size for I/O.  */
        int             __pad2;
        long            st_blocks;      /* Number 512-byte blocks allocated. */
        long            st_atime;       /* Time of last access.  */
        unsigned long   st_atime_nsec;
        long            st_mtime;       /* Time of last modification.  */
        unsigned long   st_mtime_nsec;
        long            st_ctime;       /* Time of last status change.  */
        unsigned long   st_ctime_nsec;
        unsigned int    __unused4;
        unsigned int    __unused5;
};
```

For the exercise, it's sufficient to modify the following line by accessing more of these fields:

```c
printf("%8ld %s\n", stbuf.st_size, name);
```
