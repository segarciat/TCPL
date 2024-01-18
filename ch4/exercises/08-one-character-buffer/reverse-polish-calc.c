#include <stdio.h>
#include <stdlib.h>		/* for atof */
#include <ctype.h>
#include <math.h>		/* for fmod */

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'

int getop(char[]);
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
		case 'P': /* peek */
			printf("\t%.8g\n", peek());
			break;
		case 'D': /* duplicate */
			push(peek());
			break;
		case 'S': /* swap */
			op2 = pop();
			double temp = pop();
			push(op2);
			push(temp);
			break;
		case 'C': /* clear */
			clear();
			break;
		case 'E':
			push(exp(pop()));
			break;
		case 'W':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case 'N':
			push(sin(pop()));
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL  100             /* maximum depth of val stack */

int sp = 0;                             /* next free stack position (stack pointer) */
double val[MAXVAL];             /* value stack */

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


static char buf = EOF;       /* buffer for ungetch */

int getch(void)         /* get a (possibly pushed back) character */
{
	if (buf == EOF)
	    return getchar();
	else {
	    int c = buf;
	    buf = EOF;
	    return c;
	}
}

void ungetch(int c)     /* push character back on input */
{
	/*
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
		*/
	buf = c;
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand (handles negative operands) */
int getop(char s[])
{
	int i, c, d;
	while ((s[0] = c = getch()) == ' ' || c == '\t')	/* skip white space */
			;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.') {
		if (c == '-') {
			d = getch();
			if (isdigit(d) || d == '.')
				s[++i] = c = d;
			else
				ungetch(d);
		}
		if (s[1] == '\0')
			return c;		/* not a number */
	}
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
