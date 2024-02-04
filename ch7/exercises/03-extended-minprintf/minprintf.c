#include <stdio.h>	/* printf */
#include <limits.h>	/* INT_MAX */
#include <ctype.h>	/* isdigit */
#include <stdlib.h>	/* atoi */
#include <stdarg.h>	/* va_list, va_start, va_arg, va_end */
			/* va_list is used to declare a variable that will refer to each argument in turn */
			/* va_start initializes our variable to the first unnamed argument */
			/* va_arg returns one argument and steps our variable to the next */
			/* va_end does whatever cleanup is necessary, must be called before function ends */

#define DEFAULT_PRECISION 6

void minprintf(char*, ...);

int main()
{
    int age = 17;
    minprintf("My name is %s and I am %d years old\n", "Boiji", age);
    minprintf("In hex, that is: %x\n", age);
    char *s = "hello, world";
    minprintf(":%s:\n", s);
    minprintf(":%10s:\n", s);
    minprintf(":%.10s:\n", s);
    minprintf(":%-10s:\n", s);
    minprintf(":%.15s:\n", s);
    minprintf(":%-15s:\n", s);
    minprintf(":%15.10s:\n", s);
    minprintf(":%-15.10s:\n", s);
}

/* minprintf: minimal printf with variable argument list
 * ... means that the number and types of the arguments may vary; may only appear at the end of an argument list.
 * */
void minprintf(char *fmt, ...)
{
    va_list ap;		/* points to each unnamed arg in turn */
    char *p, *sval, conversion[50];
    int ival, minwidth, precision, left;
    double dval;
    unsigned uival;

    va_start(ap, fmt);	/* make ap point to the 1st unnamed arguent. See Appendix B7, page 254 */
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    putchar(*p);
	    continue;
	}
	p++;
	minwidth = 0;
	precision = 0;
	left = 0;
	if (*p == '-') { /* left adjustment set */
	    left = 1;
	    ++p;
	}
	if (isdigit(*p)) {
	    minwidth = atoi(p);
	    while(isdigit(*p))
		p++;
	}
	if (*p == '.') {
	    precision = atoi(++p);
	    while (isdigit(*p))	/* skip digits we just read */
		p++;
	}
	sprintf(conversion, (left) ? "%%-*.*%c" : "%%*.*%c", *p);
	switch(*p) {
	    case '%':
		putchar('%');
		break;
	    case 'c':
		ival = va_arg(ap, int);
		printf("%c", ival);
		break;
	    case 'x':
	    case 'X':
		uival = va_arg(ap, unsigned);
		printf(conversion, minwidth, precision, uival);
		break;
	    case 'o':
	        uival = va_arg(ap, unsigned);
		printf(conversion, minwidth, precision, uival);
		break;
	    case 'u':
		uival = va_arg(ap, unsigned);
		printf(conversion, minwidth, precision, uival);
		break;
	    case 'd':
	    case 'i':
		ival = va_arg(ap, int);
		printf(conversion, minwidth, precision, ival);
		break;
	    case 'f':
		dval = va_arg(ap, double);
		printf(conversion, minwidth, (precision == 0) ? 6: precision, dval);
		break;
	    case 's':
		sval = va_arg(ap, char *);
		printf(conversion, minwidth, (precision == 0) ? INT_MAX: precision, sval);
		break;
	    default:
		putchar(*p);
		break;
	}
    }
    va_end(ap);	/* clean up when done */
}
