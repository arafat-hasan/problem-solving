/**************************************************************
*   FILE NAME:  Beat the Spread!-10812.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   21 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
int main() {

    long long t, sum, diff;
    scanf("%lli", &t);
    while(t-- && scanf("%lli %lli", &sum, &diff) == 2) {

        if(diff > sum || (sum - diff) % 2 == 1) {

            printf("impossible\n");
        }

        else {

            printf("%lli %lli\n", (sum + diff)/2, (sum - diff) / 2);

        }
    }

    return 0;
}
