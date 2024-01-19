#include <string.h> /* for strlen */
#include <stdio.h> /* for printf */

void reverse(char[]);

int main()
{
    char s[] = "hello world";
    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);
}


int recreverse(char s[], int left, int right)
{
    if (right - left > 2)
	recreverse(s, left + 1, right - 1);
    /* swap */
    int temp = s[left];
    s[left] = s[right];
    s[right] = temp;
}

/* reverse: reverses a string s in place */
void reverse(char s[])
{
    int n = strlen(s);
    recreverse(s, 0, n - 1);
}
