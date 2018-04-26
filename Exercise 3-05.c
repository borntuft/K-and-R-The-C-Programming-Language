/*

Exercise 3-5. Write the function itob(n,s,b) that converts the integr n
into a base b character representation in the string s. In particular,
itob(n,s,16) formats n as a hexadecimal integer in s.

Date:       April 26, 2018

Author:     BornTuft

*/

#include <stdio.h>
#include <string.h>
#define LIMIT 1000

void itob (int n, char s[], int b);
void reverse (char s[]);

int main (void)
{
    int n = 1728;
    int b = 16;
    char s[LIMIT];

    printf("Integer: %d\n", n);
    itob (n, s, b);
    printf("Base %d: %s\n", b, s);

    return 0;
}

void reverse (char s[])
{
    int c = 0;
    int i = 0;
    int j = 0;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

}

void itob (int n, char s[], int b)
{
    int counter = 0;
    int quotient = 0;
    int remainder = 0;

    quotient = n;
    do{
        remainder = quotient % b;
        quotient = quotient / b;

        if (remainder >=10)
            s[counter++] = remainder + 55;
                /* If the remainder is 10 or more, we add 55 to
                to the remainder to access alphabetic letters */
        else
            s[counter++] = remainder + '0';
    } while (quotient > 0);

    s[counter] = '\0';

    reverse(s);

}
