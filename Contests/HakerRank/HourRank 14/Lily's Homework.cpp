/***************************************************************
*   FILE NAME:  Lily's Homework.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   02 Nov 16      New         1.0         Completed, not accepted
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, c, d, swap, count=0,i;
    scanf("%i", &n);
    int array[n+5],sec[n+5];
    for(i=0; i<n; i++) {
        scanf("%i",  &array[i]);
        sec[i]=array[i];
    }

    for (c = 0 ; c < ( n - 1 ); c++) {
        for (d = 0 ; d < n - c - 1; d++) {
            if (array[d] > array[d+1]) {		/* For decreasing order use < */
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }

    for(i=0; i<n; i++) {
        if(sec[i]==array[i])
            count++;
    }

    if(count%2==0) {
        printf("%i\n", count/2);
    }
    else {
        printf("%i\n", ((count+1)/2)+1);
    }
    return 0;
}
