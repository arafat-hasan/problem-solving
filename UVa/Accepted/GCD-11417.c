/***********************************************************************
*   FILE NAME: GCD-11417.c
*
*   PURPOSE:
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         Completed, accepted
***********************************************************************/
#include <stdio.h>
int GCD ( int a, int b );
int main() {

    int i, j, G, N;
    while(scanf("%i", &N) == 1 && N) {
        G=0;
        for(i=1; i<N; i++) {
            for(j=i+1; j<=N; j++)
            {
                G+=GCD(i,j);
            }
        }
        printf("%i\n", G);
    }


    return 0;
}


int GCD ( int a, int b )
{
    if ( a==0 ) return b;
    return GCD ( b%a, a );
}
