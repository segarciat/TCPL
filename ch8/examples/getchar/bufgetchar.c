#include "syscalls.h" /* read */

#define FD_STDOUT 1

int getchar(void);

/* sample main program that uses getchar to write input to output */
int main()
{
    int c;
    const int BYTES_TO_WRITE = 1;
    while ((c = getchar()) != EOF)
        write(FD_STDOUT, (char *) &c, BYTES_TO_WRITE);
    c = '\n';
    write(FD_STDOUT, (char *) &c, BYTES_TO_WRITE);
    return 0;
}

/* getchar: unbuffered single character input */
int getchar(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
