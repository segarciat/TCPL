#include <string.h> /* strlen */
#include <stdio.h>

void reverse(char s[]);

int main()
{
    char s[] = "hello";
    printf("%s reversed is: ", s);
    reverse(s);
    printf("%s\n", s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
	/* swap */
	c = s[i];
	s[i] = s[j];
	s[j] = c;

	/* equivalent using comma operator and on a single line 
	 *
	 * c = s[i], s[i] = s[j], s[j] = c;
	 * */
    }
}
