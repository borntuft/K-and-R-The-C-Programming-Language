/*

Write the function any(s1, s2), which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location.


Version:    1

Date:       April 9, 2018

Author:     BornTuft

*/

#include <stdio.h>

int any (char string1[], char string2[]);


int main(void)
{
    char s1[] = "58M2Y51VB"; /* This is the string that will be checked*/
    char s2[] = "AAAAAVAAA"; /* The letter M will be found in position / element 2 of string above  */

    printf("Location: %i\n\n", any (s1, s2));

    return 0;
}

int any (char string1[], char string2[])
{
    int i = 0;
    int j = 0;

    for (i = 0; string1[i] != '\0'; i++){
        for (j = 0; string2[j] != '\0'; j++){
            if (string2[j] == string1[i])
                return i;
        }
    }

    return -1 ; // Default return of -1 to signify no position location found

}
