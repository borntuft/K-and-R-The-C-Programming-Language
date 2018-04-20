/*

Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
that begin at position p inverted (i.e., I changed into 0 and vice versa), leaving
the others unchanged.

Version:    1

Date:       April 14, 2018

Author:     BornTuft

*/

#include <stdio.h>

unsigned invert (unsigned x, int p, int n);

int main(void)
{

    unsigned    decimalX        =   28;

    int         positionStart   =   5;
    int         numberOfBits    =   4;

/*
    decimalX initializes with 170 or 10101010 in binary

    program will invert bits in positions 4,3,2 (010)of decimalX
    to 101 and return a value of 182 (binary 10110110)

*/

    printf("%u", invert (decimalX, positionStart, numberOfBits));

    return 0;

}

unsigned invert (unsigned x, int p, int n){

    x = x ^ (~(~0u << n) << (p + 1 - n));

    return x;

}


