#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    double op;	/* operand */
    char *endp; /* pointer to end of current argument */

    while (--argc > 0) {
	double op = strtod(*++argv, &endp);
	if (*endp == '\0') /* it was a number */
	    push(op);
	else if (strlen(*argv) == 1) { /* length is 1 */
	    switch (**argv) {
		case '+':
		    push(pop() + pop());
		    break;
		case '-':
		    op = pop();
		    push(pop() - op);
		    break;
		case '*':
		    push(pop() * pop());
		    break;
		case '/':
		    op = pop();
		    if (op != 0.0)
			push(pop() / op);
		    else {
			printf("error: divsion by 0");
			return 1; /* exit */
		    }
		    break;
		default:
		    printf("invalid operation: %s\n", *argv);
		    return 1;
	    }
	} else {
	    printf("invalid argument: %s\n", *argv);
	    return 1;	/* exit */
	}
    }
    printf("%f\n", pop()); 
    return 0;
}
