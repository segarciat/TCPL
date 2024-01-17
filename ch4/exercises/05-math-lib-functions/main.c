#include <stdio.h>
#include <stdlib.h>		/* for atof */
#include <math.h>		/* for fmod */

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'

int getop(char s[]);
void push(double);
double pop(void);
double peek(void);
void clear(void);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
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
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case 'p': /* peek */
			printf("\t%.8g\n", peek());
			break;
		case 'd': /* duplicate */
			push(peek());
			break;
		case 's': /* swap */
			op2 = pop();
			double temp = pop();
			push(op2);
			push(temp);
			break;
		case 'c': /* clear */
			clear();
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'w':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case 'n':
			push(sin(pop()));
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

