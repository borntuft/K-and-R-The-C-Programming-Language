/*

Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parameter?

Date:   March 23, 2018

Author: BornTuft

Version 2

------------
Inputted Data:

1234567890123456789012345678901234567890123456789012345678901234567890
123456789	12345678	1234567	123456	12345	123	12		1

1234567890123456789012345678901234567890123456789012345678901234567890
					1

Outputted Data:

1234567890123456789012345678901234567890123456789012345678901234567890
123456789 12345678  1234567   123456    12345     123       12
1

1234567890123456789012345678901234567890123456789012345678901234567890
                                                  1

------------

*/

#include <stdio.h>
#define COLUMNS 10
#define MAXLINE 1000

void getInputLine(char inputLine[]);
void printInputline(char inputLine[]);

int main(void)
{
    char inputLine[MAXLINE];

    getInputLine(inputLine);

    printInputline(inputLine);

    return 0;
}

void getInputLine(char inputLine[])
{
    int letter  = 0;
    int counter = 0;
    while (counter < MAXLINE && (letter = getchar()) != EOF){
        inputLine[counter] = letter;
        ++counter;
    }
    inputLine[counter] = '\0';
}

void printInputline(char inputLine[])
{
    int spaces = 0;
    int counter = 0;

    while (inputLine[counter] != '\0') {
        ++spaces;
        if (inputLine[counter] == '\t'){
            while (spaces <= COLUMNS){
                printf(" ");
                ++spaces;
            }
        }
        else{
            if (inputLine[counter] == '\n')
                spaces = 0;
            putchar(inputLine[counter]);
        }
        if (spaces >= COLUMNS)
            spaces = 0;
        ++counter;
    }
}
