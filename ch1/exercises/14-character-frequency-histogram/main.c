#include <stdio.h>

/* char size is 1 byte, or 8 bits, or 256 */
#define VALID_CHARACTER_COUNT 256

main()
{
    int c, i;
    char counts[VALID_CHARACTER_COUNT];
    for (i = 0; i < VALID_CHARACTER_COUNT; i++)
	counts[i] = 0;

    /* count characters */
    while ((c = getchar()) != EOF) {
	counts[c]++;
    }

    /* display characters with non-zero frequencies, without escaping special characters */
    for (i = 0; i < VALID_CHARACTER_COUNT; i++)
	if (counts[i] != 0)
	    printf("%c: %d\n", (char) i, counts[i]);

}
