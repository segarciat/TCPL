#include <stdio.h>
#define MAX 1000
double stack[MAX];
double *stackp = stack;

void push(double val)
{
    if (stackp < stack + MAX)
	*stackp++ = val;
    else
	printf("error: stack is full\n");
}

double pop()
{
    if (stackp != stack)
	return *--stackp;
    else {
	printf("error: stack is empty\n");
	return 0.0;
    }
}
