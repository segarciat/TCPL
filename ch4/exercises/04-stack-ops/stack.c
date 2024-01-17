#include <stdio.h>
#define MAXVAL	100		/* maximum depth of val stack */

int sp = 0;				/* next free stack position (stack pointer) */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* peek: returns value from stack without removing it */
double peek(void)
{
	if (sp > 0) {
		return val[sp - 1];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* clear: removes all items from stack */
void clear()
{
	while (sp > 0)
		pop();
}
