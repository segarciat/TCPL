#include <stdio.h>
#define HEXA_RADIX 16

int htoi(const char s[]);

int main()
{
    const char hex[] = "0x8aB";
    int expected = 2219;
    printf("%s is hex for %d decimal. htoi returns %d\n", hex, expected, htoi(hex));
}

/* htoi: converts hexadecimal string s to an integer; assumes valid hexadecimal that fits in an integer */
int htoi(const char s[])
{
    int i = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	i = 2;

    int n = 0;
    while (s[i] != '\0') {
	n *= HEXA_RADIX;
	if ('0' <= s[i] && s[i] <= '9')
	    n += (s[i] - '0');
	else if ('a' <= s[i] && s[i] <= 'z') {
	    n += (s[i] - 'a') + 10;
	} else if ('A' <= s[i] && s[i] <= 'Z') {
	    n += (s[i] - 'A') + 10;
	}
	i++;
    }
    return n;
}
