/*

Exercise 3-2. Write a function escape (s, t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters

Date:       April 22, 2018

Author:     BornTuft

*/

void escape (char s[], char t[]);
void convert (char s[], char t[]);

#include <stdio.h>
#define MAX 20

int main (void)
{

    int c = 0;
    int i = 0;

    char originalString[MAX];
    char escapedString[MAX * 2];
    char convertedString[MAX];

    while (i < (MAX - 1) && (c = getchar()) != EOF)
        originalString[i++] = c;
    originalString[i] = '\0';

    printf("\n\nOriginal String: %s\n", originalString);
    escape (escapedString, originalString);
    convert (convertedString, originalString);

    return 0;
}

void convert (char s[], char t[])
{
    int i = 0;
    int j = 0;

    while ((j < MAX -1) && t[i] != '\0'){
        switch (t[i]){
            case '\\':
                switch (t[i+1]){
                    case 'n':
                        s[j++] = '\n';
                        i = i + 2;
                        break;
                    case 't':
                        s[j++] = '\t';
                        i = i + 2;
                        break;
                    default:
                        break;
                }
                break;
            default:
                s[j++] = t[i++];
                break;
        }
    }

    s[j] = '\0';

    printf("Real String: %s\n", s);
}



void escape (char s[], char t[])
{

    int i = 0;
    int j = 0;

    while ((j < MAX - 1) && t[i] != '\0'){
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

    printf("Escaped String: %s\n", s);
}
