#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
main()
{
    /* Declaring multiple variables of type int */
    int fahr, celsius;
    int lower, upper, step;

    /* Initialize variables to value */
    lower = 0; /* lower limit of temperature table */
    upper = 300;
    step = 20;

    fahr = lower;
    /* while loop */
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
	/* format string for printf */
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;	
    }
}
