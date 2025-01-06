/**************************************************************
*   FILE NAME:  Factorial You Must be Kidding-10323.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   24 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main() {

    int n, i;
    long long factorial;
    while(scanf("%i", &n)==1) {

        if(n>7&&n<14) {
            factorial=1;
            for( i=1; i<=n; i++) {
                factorial=factorial*i;
            }
            printf("%lli\n", factorial);
        }

        else if(n<0) {
            if(n%2) {
                printf("Overflow!\n");
            }
            else {
                printf("Underflow!\n");
            }

        }

        else if(n<8) {		//if n<0 ans will be Overflow
            printf("Underflow!\n");
        }

        else {
            printf("Overflow!\n");
        }
    }
    return 0;
}
