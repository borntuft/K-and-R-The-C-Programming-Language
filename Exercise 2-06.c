/*

Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the other
bits unchanged.

Version:    1

Date:       April 10, 2018

Author:     BornTuft

*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{

    unsigned    decimalX        =   170;
    unsigned    decimalY        =   85;

    int         positionStart   =   4;
    int         numberOfBits    =   8;

/*
    decimalX initializes with 170 or 10101010 in binary
    decimalY initializes with 85  or 01010101 in binary

    program will acheive this by setting the bits in positions 4,3,2 of decimalX
    to match the bits in positions 4,3,2 of decimalY

*/

    printf("%u", setbits(decimalX, positionStart, numberOfBits, decimalY));

    return 0;

}

unsigned setbits(unsigned x, int p, int n, int y){

    unsigned tempX = 0;
    unsigned tempY = 0;

    printf("\n\n%u\n\n", ~(~0u << n));

    tempX = (x >> (p+1-n)) & ~(~0u << n);
    tempX = (tempX << (p - n + 1));
    tempY = (y >> (p+1-n)) & ~(~0u << n);
    tempY = (tempY << (p - n + 1));

    return x - tempX + tempY;

}


