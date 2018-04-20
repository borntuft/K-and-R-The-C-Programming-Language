/* NOT COMPLETE
Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines

Author: BornTuft

Date:   March 14, 2018

Notes:  Version 1

*/

#include <stdio.h>
#define TRUE 0
#define FALSE 0
#define MAXLINE 1000

int getLine(char inputLine[]);
void stripLine(char inputLine[], int counter);

int main (void){

    char    inputLine[MAXLINE];
    stripLine(inputLine, getLine(inputLine));

}

int getLine(char inputLine[]){

    int c = 0;
    int counter = 0;

    while ((c = getchar()) != EOF && c!= '\n'){
        inputLine[counter] = c;
        ++counter;
    }
    inputLine[counter] = '\n';
    ++counter;
    inputLine[counter] = '\0';
    ++counter;

    printf("\n\n");

    for (int i = 0; i < counter; ++i)
        if (inputLine[i] == '\0')
            printf("Value of Element [%d] is: \\0\n", i);
        else if (inputLine[i] == '\n')
            printf("Value of Element [%d] is: \\n\n", i);
        else if (inputLine[i] == 32)
            printf("Value of Element [%d] is: (space)\n", i);
        else if (inputLine[i] == '\t')
            printf("Value of Element [%d] is: \\t\n", i);
        else
            printf("Value of Element [%d] is: %c\n", i, inputLine[i]);

    printf("\n\n");
    return counter;

}

void stripLine(char inputLine[], int counter)
{

    char    editedLine[MAXLINE];
    char    lastChar;
    int     numberOfBlanksAndTabs = 0;
    int     i = 0;

    /*
    This for statement has the counter start at 2 less than as we do not
    need to worry about the last 2 elements in the array (\n and \0)
    */
    for (i = counter - 2; i >= 0; --i){

        lastChar = inputLine[i];

        /*
        This if statement will determine the total number of trailing blanks and tabs that occur
        in the original line of input
        */
        if ((inputLine[i] == '\t' && (lastChar == '\t' || lastChar == 32)) || (inputLine[i] == 32 && (lastChar == '\t' || lastChar == 32)))
            ++numberOfBlanksAndTabs;
    }

    for (i = 0; i < (counter - 2 - numberOfBlanksAndTabs); ++i){
        editedLine[i] = inputLine[i];
    }

    editedLine[i] = '\n';
    ++i;
    editedLine[i] = '\0';
    ++i;

    for (i = 0; i < (counter - numberOfBlanksAndTabs); ++i)
        if (inputLine[i] == '\0')
            printf("Value of Element [%d] is: \\0\n", i);
        else if (inputLine[i] == '\n')
            printf("Value of Element [%d] is: \\n\n", i);
        else if (inputLine[i] == 32)
            printf("Value of Element [%d] is: (space)\n", i);
        else if (inputLine[i] == '\t')
            printf("Value of Element [%d] is: \\t\n", i);
        else
            printf("Value of Element [%d] is: %c\n", i, inputLine[i]);

    printf("\n\n");




}
