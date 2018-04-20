/*

Exercise 3-2. Write a function escape (s, t) that converts characters like
newline and tab into visible escape sequences like \n and \ t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters

Date:       April 19, 2018

Author:     BornTuft

*/

void escape (char s[], char t[]);

#include <stdio.h>
#define MAX 1000

int main (void)
{

    int c = 0;
    int i = 0;

    char originalString[MAX];
    char escapedString[MAX];

    while (i < (MAX - 1) && (c = getchar()) != EOF)
        originalString[i++] = c;
    originalString[i] = '\0';

    printf("\n\nOriginal String: %s\n", originalString);
    escape (escapedString, originalString);
    printf("Escaped String: %s\n", escapedString);

    return 0;
}

void escape (char s[], char t[])
{

    int i = 0;
    int j = 0;

    while ((j < MAX - 1) && t[i] != '\0')
    {
        switch (t[i]){
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}
