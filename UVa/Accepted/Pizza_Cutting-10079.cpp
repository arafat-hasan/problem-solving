/**************************************************************
*   FILE NAME:  Pizza Cutting-10079.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   27 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>

int main() {

    long long n;
    while(scanf("%lli", &n)==1) {
        if(n < 0)
            break;
        printf("%lli\n", ((n*(n + 1))/2)+1);
    }

    return 0;
}
