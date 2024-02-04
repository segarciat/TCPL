#include <stdarg.h>	/* va_list, va_start, va_arg, va_end */
#include <stdio.h>	/* scanf */

void minscanf(char *fmt, ...);

int main()
{
    int age;
    printf("Enter an integer: ");
    minscanf("%d", &age);
    printf("Received: %d\n", age);
}

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap;	/* points to each unnamed argument in turn */
    char *p, *sval;
    int* pival;
    float* pfval;

    va_start(ap, fmt);	/* make ap point to the 1st unnamed argument */
    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    scanf(p, sval);
	    continue;
	}
	switch(*++p) {
	    case 'd':
		pival = va_arg(ap, int *);
		scanf("%d", pival);
		break;
	    case 'f':
		pfval = va_arg(ap, float*);
		scanf("%f", pfval);
		break;
	    case 'c':
		sval = va_arg(ap, char*);
		scanf("%c", sval);
		break;
	    default:
		scanf(p, sval);
		break;
	}
    }
    va_end(ap);
}
