/*

Exercise 1-23. Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly. C comments do not nest.

Version:    2

Date:       March 30, 2018

Author:     BornTuft

*/
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define LIMIT 10000

void getCode(char inputCode[]);
void removeComments(char inputCode[], char parsedCode[]);

int main (void)
{
    char inputCode[LIMIT];
    char parsedCode[LIMIT];

    getCode(inputCode);
    removeComments(inputCode, parsedCode);

    printf("%s", parsedCode);

    return 0;

}

void getCode(char inputCode[])
{
    int character = 0;
    int counter = 0;

    while ((character = getchar()) != EOF){
        inputCode[counter++] = character;
    }

    inputCode[counter] = '\0'; /* Added null character to signify end of string */
}

void removeComments(char inputCode[], char parsedCode[])
{

    int counterInput    =   0;
    int counterParsed   =   0;
    int commentFound    =   FALSE;

    while (inputCode[counterInput]){
        if (inputCode[counterInput - 1] != '\"' && inputCode[counterInput] == '/' && inputCode[counterInput + 1] == '*')
            commentFound = TRUE;

        if (inputCode[counterInput] == '*' && inputCode[counterInput + 1] == '/' && inputCode[counterInput + 2] != '\"'){
            commentFound = FALSE;
            counterInput = counterInput + 2;
        }

        if (commentFound)
            ++counterInput;
        else{
            parsedCode[counterParsed] = inputCode[counterInput];
            ++counterInput;
            ++counterParsed;
        }

    }

    parsedCode[counterParsed] = '\0';

}
