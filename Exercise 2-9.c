/*

Exercise 2-9. In a two's complement number system, x &.= (x-1) deletes the
rightmost l-bit in x. Explain why. Use this observation to write a faster ver-
sion of bitcount.

Version:    1

Date:       April 18, 2018

Author:     BornTuft

*/

#include <stdio.h>

int bitcountOriginal (unsigned x);
int bitcountExercise (unsigned x);

int main()
{
    unsigned x = 255;

    printf("%d\n\n", bitcountOriginal(x));
    printf("%d\n\n", bitcountExercise(x));

    return 0;

}

int bitcountExercise (unsigned x)
{

    int b = 0;

    while (x != 0){
        x &= (x - 1);
        b++;
        x >>= 1;
    }

    printf("\nThis function deletes the rightmost 1 bit by using the AND & bitwise operator to compare the value of x an subtract 1. That result then becomes x and is right shifted by 1 bit and compared again to the new x - 1. The number below shows the number of 1-bits in this integer\n\n");

    return b;

}

int  bitcountOriginal (unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    printf("\nThis function does not delete any of the bits. It compares the rightmost 1 bit by using the AND & bitwise operator to \"1\". b is then incremented. x is then right shifted by 1 bit and the rightmost 1 bit is compared again to \"1\". The number below shows the number of 1-bits in this integer.\n\n");

    return b;

}

