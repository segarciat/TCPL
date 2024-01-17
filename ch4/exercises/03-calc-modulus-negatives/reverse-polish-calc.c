#include <stdio.h>
#include <stdlib.h>		/* for atof */
#include <ctype.h>
#include <math.h>		/* for fmod */

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'

int getop(char s[]);
void push(double);
double pop(void);

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

#define BUFSIZE 100
static char buf[BUFSIZE];       /* buffer for ungetch */
static int bufp = 0;            /* next free position in buf */

int getch(void)         /* get a (possibly pushed back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
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
