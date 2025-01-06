/**************************************************************
*   FILE NAME:  Hashmat the Brave Warrior-10055.cpp
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

    long long a, b;
    while(scanf("%lli %lli", &a, &b)==2) {
        if(b > a)
            printf("%lli\n", b - a);
        else
            printf("%lli\n", a - b);
    }

    return 0;
}
