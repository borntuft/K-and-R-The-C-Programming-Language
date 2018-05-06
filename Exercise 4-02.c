/*

Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent.

Date:       May 6, 2018

Author:     BornTuft

*/

#include <stdio.h>
#include <ctype.h>

double atof (char s[]);

int main (void)
{
    char s[] = "123.45e-6";
    printf("This Should Be The Result: %g\n", 123.45e-6); // This is how C outputs the double variable
    printf("This Is what The Function Returns: %g\n", atof(s)); // This is how the atof function returns the string
    return 0;                                                   // Output of the two should match
}

double atof (char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* Skip all white spaces */
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.00 * val + (s[i] - '0');
        power *= 10.00;
    }

    if (tolower(s[i++]) == 'e') {
        int exponentSign = 0;
        int exponent = 0;
        double exponentPower = 1.00;
        exponentSign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
            i++;

        if (isdigit(s[i+1])) { // Determine if exponent is 2 characters in length
            exponent += (s[i] - '0') * 10;
            exponent += (s[i+1] - '0');
        }
        else
            exponent += (s[i] - '0');

        for (int i = 0; i < exponent; i++)
            exponentPower *= 10;

        if (exponentSign == -1 )
            return ((sign * val / power) / (exponentPower));
        else
            return ((sign * val / power) * (exponentPower));

    }
    else
        return sign * val / power;
}
