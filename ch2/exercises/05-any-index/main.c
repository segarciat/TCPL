#include <stdio.h>

int any(const char s1[], const char s2[]);

int main()
{
    const char s1[] = "hello";
    const char s2[] = "bye";
    int expected = 1;
    printf("the \"any\" function applied to \"%s\" and \"%s\" should return %d\n", s1, s2, expected);
    printf("the actual result is %d\n", any(s1, s2));
}

/* any: returns the first location in the string s1 where any character from the string s2 occurs, or -1
 * if s1 contains no characters from the string s2 */
int any(const char s1[], const char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
	char c = s1[i];
	for (j = 0; s2[j] != '\0'; j++)
	    if (s2[j] == c)
		return i;
    }
    return -1;
}
