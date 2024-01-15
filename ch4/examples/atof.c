#include <stdio.h>
#include <ctype.h> /* isspace */
#define MAXLINE 100

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getline(char line[], int max);

    sum = 0;
    while (getline(line, MAXLINE) > 0)
	printf("\t%g\n", sum += atof(line));
    return 0;
}

/* getline:g et line into s, return length*/
int getline(char s[], int lim)
{
	int c, i;
	i = c = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* atof: convert string s to double. Not high quality, according to book; recommend atof in stdlib.h */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for(i = 0; isspace(s[i]); i++) /* skip white space */
	;
    sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] == '-')
	i++;
    for (val = 0.0; isdigit(s[i]); i++)
	val = 10.0 * val + (s[i] - '0');
    if (s[i] = '.')
	i++;
    for (power = 1.0; isdigit(s[i]); i++) {
	val = 10.0 * val + (s[i] - '0');
	power *= 10.0;
    }
    return sign * val / power;
}
