#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main()
{
    char s1[] = "hello world";
    const char s2[] = "good bye";
    char expected[] = "hllwrl";

    printf("Squeezing \"%s\" with \"%s\" should result in \"%s\"\n", s1, s2, expected);
    squeeze(s1, s2);
    printf("The implementation yielded \"%s\"\n", s1);
}


/* squeeze_c: delete all c from s. Implementation from page 47. */
void squeeze_c(char s[], char c)
{
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++)
	if (s[i] != c)
	    s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze: delete all characters in s1 that match any character in s2 */
void squeeze(char s1[], const char s2[])
{
    int i;
    for (i = 0; s2[i] != '\0'; i++)
	squeeze_c(s1, s2[i]);
}
