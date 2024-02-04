#include <stdio.h>	/* printf */
#include <stdarg.h>	/* va_list, va_start, va_arg, va_end */
			/* va_list is used to declare a variable that will refer to each argument in turn */
			/* va_start initializes our variable to the first unnamed argument */
			/* va_arg returns one argument and steps our variable to the next */
			/* va_end does whatever cleanup is necessary, must be called before function ends */


void minprintf(char*, ...);

int main()
{
    minprintf("My name is %s and I am %d years old\n", "Boiji", 16);
}

/* minprintf: minimal printf with variable argument list
 * ... means that the number and types of the arguments may vary; may only appear at the end of an argument list.
 * */
void minprintf(char *fmt, ...)
{
    va_list ap;		/* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);	/* make ap point to the 1st unnamed arguent. See Appendix B7, page 254 */
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    putchar(*p);
	    continue;
	}
	switch(*++p) {
	    case 'd':
		ival = va_arg(ap, int);
		printf("%d", ival);
		break;
	    case 'f':
		dval = va_arg(ap, double);
		printf("%f", dval);
		break;
	    case 's':
		for (sval = va_arg(ap, char*); *sval; sval++)
		    putchar(*sval);
		break;
	    default:
		putchar(*p);
		break;
	}
    }
    va_end(ap);	/* clean up when done */
}
