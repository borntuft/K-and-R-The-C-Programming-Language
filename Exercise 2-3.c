/*

Exercise 2·3. Write the function htoi (s), which converts a string of hexa-
decimal digits (including an optional Ox or ox) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F.


Version:    2

Date:       April 8, 2018

Author:     BornTuft

*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define LIMIT 1000

void getHexadecimal(char inputHexadecimal[]);
int  getDigitLocations(char inputHexadecimal[]);
void convertHexToInt(char inputHexadecimal[], int outputInteger, int digitLocations);
int convertCharToInt(char hexChar);

int main (void)
{

    char inputHexadecimal[LIMIT];
    int  outputInteger = 0;
    int  digitLocations = 0;

    getHexadecimal(inputHexadecimal);
    digitLocations = getDigitLocations(inputHexadecimal);
    convertHexToInt(inputHexadecimal, outputInteger, digitLocations);

}

void getHexadecimal(char inputHexadecimal[])
{
    char userInput = 0;
    int counter = 0;

    while ((userInput = getchar()) != '\n')
        if (isxdigit(userInput))
            inputHexadecimal[counter++] = userInput;

    inputHexadecimal[counter] = '\0';
}

int getDigitLocations(char inputHexadecimal[])
{

    /* This set of code determines how many digit locations are in the hexadecimal number */
    int digitLocations = 0;
    while (inputHexadecimal[++digitLocations])
        ;
    return digitLocations - 1; /* digitLocations is decremented to make caluclations of powers easier */

}

void convertHexToInt(char inputHexadecimal[], int outputInteger, int digitLocations)
{
    int hexCounter = digitLocations;
    int intCounter = 0;
    int intValueOfHex = 0;

    while (intCounter <= digitLocations){
        intValueOfHex = convertCharToInt(inputHexadecimal[hexCounter--]);
        outputInteger = outputInteger + (intValueOfHex * pow(16.00, intCounter++));
    }

    printf("\n\nThe hexadecimal input of %s converts to an integer of %i.\n", inputHexadecimal, outputInteger);

}

int convertCharToInt(char hexChar)
{
    if (isdigit(hexChar))
        return (hexChar - 48);
    else if(isalpha(hexChar)){
        hexChar = toupper(hexChar);
        return (hexChar - 55);
    }
    else
        return 0;

}
