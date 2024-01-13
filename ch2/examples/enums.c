#include <stdio.h>

/* By default, first is 0, second is 1, and so on */
enum boolean { NO, YES};

/* You can assign values explicitly */
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', 
	       NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

/* Setting the starting value, rest follow progression */
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
	      JUL, AUG, SEP, OCT, NOV, DEC };

int main()
{
    /* Variables can be declared to be of enum type */
    enum months myMonth = JUN;
    /* However, compiler need not check for this */
    enum months invalidMonth = -1;
    printf("June is the %d month\n", myMonth);
    printf("Invalid month: %d\n", invalidMonth);
}
