/*

Exercise 2-1. Write a program to determine the ranges of char, short,
and long variables, both signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you com-
pute them: determine the ranges of the various floating-point types.

Version:    1

Date:       April 5, 2018

Author:     BornTuft

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Printing From Headers:\n\n");

    printf("Signed char min: %i\n", SCHAR_MIN);
    printf("Signed char max: %i\n\n", SCHAR_MAX);

    printf("Unsigned char min: 0\n");
    printf("Unsigned char max: %u\n\n", UCHAR_MAX);


    printf("Signed short min: %i\n", SHRT_MIN);
    printf("Signed short max: %i\n\n", SHRT_MAX);

    printf("Unsigned short min: 0\n");
    printf("Unsigned short max: %u\n\n", USHRT_MAX);

    printf("Signed int min: %i\n", INT_MIN);
    printf("Signed int max: %i\n\n", INT_MAX);

    printf("Unsigned int min: 0\n");
    printf("Unsigned int max: %u\n\n", UINT_MAX);

    printf("Signed long min: %li\n", LONG_MIN);
    printf("Signed long max: %li\n\n", LONG_MAX);

    printf("Unsigned long min: 0\n");
    printf("Unsigned long max: %lu\n\n", ULONG_MAX);

    printf("\n\n");

    printf("Printing From Computation:\n\n");

    long counter = 0;

    char charCounterSignedMin = 0;
    while (--charCounterSignedMin <= 0){
        --counter;
    }
    printf("Signed char min: %i\n", counter);

    counter = 0;
    char charCounterSignedMax = 0;
    while (++charCounterSignedMax >= 0){
        ++counter;
    }
    printf("Signed char max: %i\n\n", counter);


    printf("Unsigned char min: 0\n");

    counter = 0;
    unsigned char charCounterUnsignedMax = 0;
    while (++charCounterUnsignedMax){
        ++counter;
    }
    printf("Unsigned char max: %ul\n\n", counter);


    counter = 0;
    short shortCounterSignedMin = 0;
    while (--shortCounterSignedMin <= 0){
        --counter;
    }
    printf("Signed short min: %i\n", counter);

    counter = 0;
    short shortCounterSignedMax = 0;
    while (++shortCounterSignedMax >= 0){
        ++counter;
    }
    printf("Signed short max: %i\n\n", counter);


    printf("Unsigned short min: 0\n");

    counter = 0;
    unsigned short shortCounterUnsignedMax = 0;
    while (++shortCounterUnsignedMax){
        ++counter;
    }
    printf("Unsigned short max: %u\n\n", counter);

    counter = 0;
    int intCounterSignedMin = 0;
    while (--intCounterSignedMin <= 0){
        --counter;
    }
    printf("Signed int min: %i\n", counter);

    counter = 0;
    int intCounterSignedMax = 0;
    while (++intCounterSignedMax >= 0){
        ++counter;
    }
    printf("Signed int max: %i\n\n", counter);


    printf("Unsigned int min: 0\n");

    counter = 0;
    unsigned int intCounterUnsignedMax = 0;
    while (++intCounterUnsignedMax){
        ++counter;
    }
    printf("Unsigned int max: %u\n\n", counter);


}
