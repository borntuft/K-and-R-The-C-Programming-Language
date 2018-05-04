/*

Exercise 4-1. Write the function strrindex(s, t), which returns the position
of the rightmost occurrence of t in s, or - 1 if there is none.

Date:       May 4, 2018

Author:     BornTuft

*/

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getline (char line[], int max);
int strrindex (char source[], char searchfor[]);

char pattern[] = "the";

int main (void)
{
	char line[MAXLINE];
	int position = 0;

	while (getline(line, MAXLINE) > 0)
        if ((position = strrindex(line, pattern)) >= 0)
            printf("Rightmost Occurrence of \'%s\' is at position %i\n", pattern, position);

    return 0;
}

int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	int position = 0;

	for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            position = ++i;
    }

    if (position)
        return position - 1; /* 1 is deducted from position to show element in array */
    else
        return -1;

}
