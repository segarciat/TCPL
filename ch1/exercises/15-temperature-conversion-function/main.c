#include <stdio.h>

float fahrtocelsius(float fahr);

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

    fahr = lower;
    /* while loop */
    while (fahr <= upper) {
	/* format string for printf, %f for formatting float */
        printf("%3.0f %6.1f\n", fahr, fahrtocelsius(fahr));
        fahr = fahr + step;	
    }
}

/* fahrtocelsius: convert temperature measurement in degrees fahrenheit to celsius */
float fahrtocelsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}


