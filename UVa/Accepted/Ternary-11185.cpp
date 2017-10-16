/**************************************************************
*   FILE NAME:  Ternary-11185.cpp
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

    long long n, j, i, temp;
    char str[100];

    while(scanf("%lli", &n)==1) {

        if(n < 0)
            break;

        temp = n;
        i=0;
        while(temp > 0) {
            str[i] = temp % 3;
            temp /= 3;
            i++;
        }
        if(n == 0)
        str[i++] = 0;
        
        for(j = i-1; j >= 0; j--)
            printf("%i", str[j]);
        printf("\n");

    }

    return 0;
}
