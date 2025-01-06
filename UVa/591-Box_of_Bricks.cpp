/***********************************************************************
*   FILE NAME: Box of Bricks-591.cpp
*
*   PURPOSE: Solve of Uva problem p537.
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         Completed, Accepted
***********************************************************************/
#include <stdio.h>
#include <string.h>

int main() {

    int n, h[100], j=0, avg,i,sum;
    while(scanf("%i", &n) == 1 && n) {
        j++;
        sum = 0;
        for(i=0; i<n; i++) {
            scanf("%i", &h[i]);
            sum +=h[i];
        }

        avg = sum / n;
        sum = 0;
        for(i=0; i < n; i++) {
            if(h[i] > avg) {
                sum += (h[i] - avg);
            }
        }
        printf("Set #%i\nThe minimum number of moves is %i.\n\n", j, sum);
    }
    return 0;
}
