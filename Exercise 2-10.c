/*

Exercise 2-10. Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else.

Version:    1

Date:       April 9, 2018

Author:     BornTuft

*/

#include <stdio.h>

int lower(int c);
int lowerOriginal(int c);


int main(void)
{
    char c = 65;

    printf("%i", lower(c));

    return 0;
}

/* Modified code */
int lower(int c)
{
    return c = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;

}


/* Original code */
int lowerOriginal(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
