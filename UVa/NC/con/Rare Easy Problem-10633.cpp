/***********************************************************************
*   FILE NAME: Rare Easy Problem-10633.cpp
*
*   PURPOSE: Solve of Uva problem p537.
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         notCompleted, accepted
***********************************************************************/
#include <stdio.h>
int main() {

    long long n, i,m,s;
    while(scanf("%lli", &n) == 1 && n) {
s = n+1000000;
        for(i=n+1; i<= s; i++) {
            m=i/10;
            if(n==i-m)
                printf("%lli ", i);
        }

        printf("\n");

    }

    return 0;
}
