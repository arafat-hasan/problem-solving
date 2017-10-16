/**************************************************************
*   FILE NAME:  Square Numbers-11461.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   23 Oct 16      New         1.0         Completed,Accepted
***************************************************************/
#include <stdio.h>
#include <math.h>

int main() {

    int a ,b;
    while(scanf("%i %i" ,&a, &b) == 2) {

        if(a == 0 || b == 0)
            break;
        printf("%i\n", (int)(floor(sqrt(b))-ceil(sqrt(a)))+1);

    }

    return 0;
}
