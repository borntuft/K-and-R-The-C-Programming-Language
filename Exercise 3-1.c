/*

Exercise 3-1. Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only one
test inside the loop and measure the difference in run-time.

Version:    1

Date:       April 19, 2018

Author:     BornTuft

*/

#include <stdio.h>


int binsearchExercise (int x, int v[], int n);
int binsearchOriginal (int x, int v[], int n);

int main (void)
{

    int x = 9;
    int n = 9;
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    printf("%d", binsearchExercise(x, v, n));

    return 0;

}

int binsearchExercise (int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; /* found match */
    }
    return -1; /* no match */
}


int binsearch (int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; /* found match */
    }
    return -1; /* no match */
}
