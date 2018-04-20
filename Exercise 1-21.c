/*

Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stops as for detab. When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference?

Version:    1

Date:       March 24, 2018

Author:     BornTuft

----------------
Inputted Data:


Outputted Data:

----------------

*/

#include <stdio.h>
#define COLUMNS 5
#define MAXLINE 1000

void getLine(char inputLine[]);
void entab(char inputLine[]);

int main(void)
{
    char inputLine[MAXLINE];

    getLine(inputLine);
    entab(inputLine);

    return 0;
}

void getLine(char inputLine[])
{
    int letter = 0;
    int counter = 0;

    while (counter < (MAXLINE - 1) && (letter = getchar()) != EOF){
        inputLine[counter] = letter;
        ++counter;
    }
    inputLine[counter] = '\0';

}

void entab(char inputLine[])
{
    int counter = 0;
    int i = 0;
    int spaces = 0;

    while (inputLine[counter] != '\0'){
        if (inputLine[counter] == ' '){
            while (spaces <= COLUMNS){
                printf(" ");
                ++spaces;
            }
            spaces = 0;
        }
        else{
            putchar(inputLine[counter]);
            ++spaces;
        }

        ++counter;
    }
}
