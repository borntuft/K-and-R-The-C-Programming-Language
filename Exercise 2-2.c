/*

Exercise 2-2. Write a loop equivalent to the for loop above without using &&
or ||


Version:    1

Date:       April 7, 2018

Author:     BornTuft

*/

#include <stdio.h>
#define lim 6


int main(void)
{

/*

Original for loop:

for (i=O; i<lim-1 && (c=getchar()) !='\n' && c !=EOF; ++i)
    s[i] = c;

*/

    char s[lim];
    int i = 0;
    int c = getchar();

    while (c != EOF){
        if (i < lim - 1){
            if (c != '\n'){
                s[i++] = c;
                c = getchar();
            }
            else
                c = EOF;
        }
        else
            c = EOF;


    }

    s[i++]  = '\n';
    s[i]    = '\0';

    printf("%s", s);

}
