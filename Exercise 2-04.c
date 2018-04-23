/*

Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes
each character in s1 that matches any character in the string s2


Version:    1

Date:       April 8, 2018

Author:     BornTuft

*/

#include <stdio.h>

void squeeze (char s1[], char s2[]);


int main(void)
{
    char s1[] = "123456789"; /* This is the string where we will delete numbers */
    char s2[] = "12345678"; /* The numbers 1 through 8 should be deleted from the string above */

    printf("Original s1: %s\n", s1);
    squeeze (s1, s2);
    printf("Modified s1: %s\n", s1);


    return 0;
}

void squeeze (char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int counter = 0;

    while (s2[counter] != '\0'){
        while (s1[i] != '\0'){
            if (s1[i] != s2[counter]){
                s1[j++] = s1[i];
            }
            i++;
        }
        s1[j] = '\0';
        counter++;
        i = 0;
        j = 0;

    }
}
