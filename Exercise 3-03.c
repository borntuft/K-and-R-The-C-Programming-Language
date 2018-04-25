/*

Exercise 3-3. Write a function expand (s 1, s2) that expands shorthand nota-
tions like a - z in the string s1 into the equivalent complete list abc ... xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.

Date:       April 24, 2018

Author:     BornTuft

*/

#include <stdio.h>
#include <ctype.h>
#define LIMIT 1000

void getLine (char s1[]);
void expand (char s1[], char s2[]);

int main()
{
    char s1[LIMIT], s2[LIMIT];

    getLine(s1);
    expand(s1, s2);

    printf("\n%s\n\n", s2);

    return 0;

}

void getLine (char s1[])
{
    int c = 0;
    int counter = 0;

    while ((c = getchar()) != EOF && c != '\n')
        s1[counter++] = c;

    s1[counter] = '\0';
}

void expand (char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int startCharacter = 0;
    int endCharacter = 0;

    while (s1[i] != '\0') {

        switch (s1[i]){
            case '-':
                i++;
            default:
                startCharacter = s1[i];
                if (isalnum(s1[i+1]))
                    endCharacter = s1[i+1];
                else
                    endCharacter = s1[i+2];
                i++;
                break;

        }

        while (startCharacter <= endCharacter)
            s2[j++] = startCharacter++;

    }
    s2[j] = '\0';
}
