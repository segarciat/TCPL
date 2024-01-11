#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for fahr = 0, 20, ..., 300: floating-point version */
main()
{
    /* Declaring multiple variables of type float and int */
    float fahr, celsius;
    int lower, upper, step;

    /* Initialize variables to value */
    lower = 0; /* lower limit of temperature table */
    upper = 40;
    step = 2;

    /* Display table heading */
    printf("Celsius | Fahr\n");
    printf("-------------\n");

    celsius = lower;
    /* while loop */
    while (celsius <= upper) {
	/* float arithmetic */
	fahr = (9.0/5.0) * celsius + 32.0;
	/* format string for printf, %f for formatting float */
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;	
    }
}
