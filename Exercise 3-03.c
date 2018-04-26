/*

Exercise 3-3. Write a function expand (s1, s2) that expands shorthand nota-
tions like a - z in the string s1 into the equivalent complete list abc ... xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.

Date:       April 25, 2018

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

    while ((counter < LIMIT - 1) && (c = getchar()) != EOF && c != '\n')
        s1[counter++] = c;

    s1[counter] = '\0';
}

void expand (char s1[], char s2[])
{
    int counter = 0;
    int i = 0;
    int j = 0;
    int startCharacter = 0;
    int endCharacter = 0;

    while ((s1[i] != '\0'))
    {
        s2[j++] = s1[i++];
        if ((s1[i] == '-') && (isalnum(s1[i + 1])) && (isalnum(s1[i - 1])))
        {
            startCharacter = s1[i - 1];
            endCharacter   = s1[++i];
            while ((counter++ < LIMIT - 1) && (startCharacter < endCharacter - 1))
                s2[j++] = ++startCharacter;
        }
    }
    s2[j] = '\0';
}
