/***************************************************************
*   FILE NAME:  Beautiful Days at the Movies.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   02 Nov 16      New         1.0         Completed, accepted
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main() {

    long long  i, j, k, m, reverse , temp, count=0;

    scanf("%lli %lli %lli", &i, &j, &k);

    for(m = i; m <= j; m++) {

        temp = m;
        reverse = 0;
        while( temp != 0 ) {
            reverse = reverse * 10;
            reverse = reverse + temp%10;
            temp = temp/10;
        }

        if(abs(m - reverse) % k == 0) {
            count++;
        }
    }
    printf("%lli\n", count);
    return 0;
}
