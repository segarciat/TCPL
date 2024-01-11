#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300: floating-point version */
main()
{
    /* Declaring multiple variables of type float and int */
    float fahr, celsius;
    int lower, upper, step;

    /* Initialize variables to value */
    lower = 0; /* lower limit of temperature table */
    upper = 300;
    step = 20;

    /* Display table heading */
    printf("Fahr | Celsius\n");
    printf("-------------\n");

    fahr = lower;
    /* while loop */
    while (fahr <= upper) {
	/* float arithmetic */
        celsius = (5.0/9.0) * (fahr-32.0);
	/* format string for printf, %f for formatting float */
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;	
    }
}
