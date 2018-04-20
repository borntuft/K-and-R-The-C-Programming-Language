/*
Exercise 1-9. Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank.
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

main()
{
    int c;
    int blanks = FALSE;

    while ((c = getchar()) != EOF){
        if (c == ' ')
            if (blanks == FALSE) {
                blanks = TRUE;
                putchar(c);
            }
        if (c != ' '){
            blanks = FALSE;
            putchar(c);
        }
    }
}
