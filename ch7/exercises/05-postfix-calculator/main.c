#include <stdio.h>
#include <stdlib.h>		/* for atof */
#include "calc.h"

#define MAXOP 100		/* max size of operand or operator */

/* reverse Polish calculator */
int main()
{
    int read;
    double op2;
    char s[MAXOP];
    read = 1;
    while (read != EOF) {
	read = scanf("%s", s);
	if (sscanf(s, "%lf", &op2)) {
	    push(op2);
	} else {
	    switch(*s) {
	        case '+':
		    push(pop() + pop());
		    break;
	        case '*':
		    push(pop() * pop());
		    break;
	        case '-':
		    op2 = pop();
		    push(pop() - op2);
		    break;
	        case '/':
		    op2 = pop();
		    if (op2 != 0)
		        push(pop() / op2);
		    else
		        printf("error: division by zero\n");
		    break;
		case 'p':
		    printf("\t%.8g\n", pop());
		    break;
	        default:
		    printf("error: unknown command: %s\n", s);
		    break;
	    }
	}
    }
    return 0;
}
