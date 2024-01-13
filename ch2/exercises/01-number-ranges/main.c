#include <stdio.h>
#include <limits.h>
#include <float.h>

void printIntRange(char text[], long min, long max);
void printComputedIntegralRanges();
void printHeaderIntegralRanges();

int main()
{
    printHeaderIntegralRanges();
    printComputedIntegralRanges();
}

void printHeaderIntegralRanges()
{
    printf("-----NUMBER RANGES FROM STANDARD HEADERS------\n");
    printIntRange("Unsigned char", 0, UCHAR_MAX);
    printIntRange("Signed char", SCHAR_MIN, SCHAR_MAX);
    printIntRange("Unsigned short", 0, USHRT_MAX);
    printIntRange("Signed short", SHRT_MIN, SHRT_MAX);
    printIntRange("Unsigned int", 0, UINT_MAX);
    printIntRange("Signed int", INT_MIN, INT_MAX);
    printf("Unsigned long: %d to %lu\n", 0, ULONG_MAX);
    printIntRange("Signed long", LONG_MIN, LONG_MAX);
}

void printComputedIntegralRanges()
{
    printf("----- NUMBER RANGES VIA COMPUTATION-------\n");
    unsigned char smallestUnsignedChar = 0;
    unsigned char largestUnsignedChar = smallestUnsignedChar - 1;
    printf("Unsigned char: %d to %d\n", smallestUnsignedChar, largestUnsignedChar); 

    signed char smallestSignedChar = 1;
    while (smallestSignedChar > 0)
	smallestSignedChar *= 2;
    signed char largestSignedChar = smallestSignedChar - 1;
    printf("Signed char: %d to %d\n", smallestSignedChar, largestSignedChar);

    unsigned short smallestUnsignedShort = 0;
    unsigned short largestUnsignedShort = smallestUnsignedShort - 1;
    printf("Unsigned short: %d to %d\n", smallestUnsignedShort, largestUnsignedShort);

    signed short smallestSignedShort = 1;
    while (smallestSignedShort > 0)
	smallestSignedShort *= 2;
    signed short largestSignedShort = smallestSignedShort - 1;
    printf("Signed short: %d to %d\n", smallestSignedShort, largestSignedShort);
    
    unsigned int smallestUnsignedInt = 0;
    unsigned int largestUnsignedInt = smallestUnsignedInt - 1;
    printf("Unsigned int: %d to %u\n", smallestUnsignedInt, largestUnsignedInt);

    signed int smallestSignedInt = 1;
    while (smallestSignedInt > 0)
	smallestSignedInt *= 2;
    signed int largestSignedInt = smallestSignedInt - 1;
    printf("Signed int: %d to %d\n", smallestSignedInt, largestSignedInt);
    
    unsigned long smallestUnsignedLong = 0;
    unsigned long largestUnsignedLong = smallestUnsignedLong - 1;
    printf("Unsigned long: %ld to %lu\n", smallestUnsignedLong, largestUnsignedLong);

    signed long smallestSignedLong = 1;
    while (smallestSignedLong > 0)
	smallestSignedLong *= 2;
    signed long largestSignedLong = smallestSignedLong - 1;
    printf("Signed long: %ld to %ld\n", smallestSignedLong, largestSignedLong);
}

void printIntRange(char text[], long min, long max)
{
    printf("%s: %ld to %ld\n", text, min, max);
}
