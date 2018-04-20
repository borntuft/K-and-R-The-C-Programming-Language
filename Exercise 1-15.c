/*
Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion.

Author: BornTuft

Date:   March 14, 2018

Notes:  Version 1

*/

#include <stdio.h>

float convertFahrenheitToCelcius (int fahrenheit);

main()
{
    printf("Fahrenheit\tCelcius\n");
    printf("----------\t-------\n");
    int fahrenheit;
    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
        printf("%d\t\t%6.2f\n", fahrenheit, convertFahrenheitToCelcius(fahrenheit));

}

float convertFahrenheitToCelcius (int fahrenheit)
{
    float celcius = 5.0 * (fahrenheit - 32.0) / 9.0;
    return celcius;
}
