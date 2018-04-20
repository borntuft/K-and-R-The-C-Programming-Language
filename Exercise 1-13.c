/*
Exercise 1-13 (version2). Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging.

Author: BornTuft

Date:   March 14, 2018

Notes:  Displays Vertical Histogram Correctly

*/

#include <stdio.h>

#define MAXNUMBERS 10

main()
{
    int c;
    int lengthOfWord = 0;
    int lengthOfWordArray[MAXNUMBERS];
    int i;
    int j;

    /* Populate Array With Zeros */
    for (i = 0; i < MAXNUMBERS; ++i)
        lengthOfWordArray[i] = 0;

    while((c=getchar()) != EOF){
        ++lengthOfWord;
        if (c == ' ' || c == '\n'){
            lengthOfWord = lengthOfWord - 1; /* Subtracting 1 to remove carriage return from count */
            if (lengthOfWord > MAXNUMBERS)
                lengthOfWord = MAXNUMBERS;
            ++lengthOfWordArray[lengthOfWord - 1]; /* Subtracting 1 to account for placement in array */
            lengthOfWord = 0;
        }
    }

    /* Display Horizontal Histogram */
    for (i = 0; i < MAXNUMBERS; ++i){
        printf("%d letter words: ", i + 1);
        for (j = 0; j < lengthOfWordArray[i]; ++j)
            printf("x");
        printf("\n");
    }
    printf("Horizontal Histogram");

    printf("\n");
    printf("\n");

    /* Display Vertical Histogram */
    int largestColumn = 0;

    /* Determine the largest column in the histogram */
    for (i = 0; i < MAXNUMBERS; ++i)
        if (lengthOfWordArray[i] > largestColumn)
            largestColumn = lengthOfWordArray[i];

    /* Show histogram */
    for (i = 0; i < largestColumn; ++i)
    {
        for (j = 0; j < MAXNUMBERS; ++j){
            if ((i + lengthOfWordArray[j]) < largestColumn)
                printf(" ");
            else
                printf("x");
        }
        printf("\n");
    }
    /* Display Footer */
    for (j = 1; j < MAXNUMBERS; ++j)
            printf("%d", j);
    printf("\nLetter Words\nVertical Histogram\n\n\n");

}
