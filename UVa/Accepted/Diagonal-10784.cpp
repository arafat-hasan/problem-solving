/************************************************************************
*   FILE NAME:	Diagonal-10784.cpp
*
*   PURPOSE:
*
*		@author:    Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    26 Oct 2016    New             1.0         Completed, Accepted
*************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {

    long long pol, i=1;
    
    while(scanf("%lli", &pol)==1) {

        if(!pol)
            break;

        printf("Case %lli: %i\n", i, (int)ceil( -(-3-sqrt(9+8*pol))/2));
        i++;
    }

    return 0;
}
