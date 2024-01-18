#include <stdio.h>
#include <string.h> /* for strlen */



int main()
{
    
}

void ungetch(int);

/* ungets: pushes back an entire string onto the input */
void ungets(char s[])
{
    int i;
    for (i = 0; i < strlen(s); i++)
	ungetch(s[i]);
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
