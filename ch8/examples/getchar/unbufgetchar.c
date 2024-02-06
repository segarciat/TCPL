#include "syscalls.h" /* read, BUFSIZ */

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

/* getchar: simple buffered version */
int getchar(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {	/* buffer is empty */
	n = read(0, buf, sizeof buf);
	bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
