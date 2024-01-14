#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    unsigned n = 62;
    printf("total number of 1-bits in %d is %d\n", n, bitcount(n));
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
	b++;
    return b;
}
