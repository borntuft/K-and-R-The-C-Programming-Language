/*

Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions

Version:    4

Date:       April 17, 2018

Author:     BornTuft

*/

#include <stdio.h>

unsigned rightrot (unsigned x, int n);

int main(void)
{

    unsigned    decimalX        =   53;
    int         numberOfBits    =   3;

/*

    the program above assumes that we are using 8bit ints.

    decimalX initializes with 53 or 00110101 in binary

    program will right shift decimalX n (3) bit positions but we will retain
    the bit that is being shifted and move it to the left most position
    ie:

    00110101 = 53 in decimal - Beginning value
    10100110 = 166 in decimal - Final result

*/

    printf("%u", rightrot(decimalX, numberOfBits));

    return 0;

}

unsigned rightrot (unsigned x, int n){

    const int PRECISION = 8;

    return ((x >> n | ((x & ~(~0u << n)) << (PRECISION - n))));

}


