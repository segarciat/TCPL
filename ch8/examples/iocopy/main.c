#include "syscalls.h" /* read, write, BUFSIZ */

int main() /* copy input to output */
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0) 	/* 0 is file descriptor for stdin */
	write(1, buf, n);			/* 1 is file descriptor for stdout */
    return 0;
}
