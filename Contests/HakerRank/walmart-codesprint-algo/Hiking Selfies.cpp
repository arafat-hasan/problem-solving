/**************************************************************
*   FILE NAME:  Hiking Selfies.cpp
*
*   PURPOSE:    
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------------
*   29 Oct 16      New         1.0         Completed,Accepted
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
int nCr(int n, int r);
int factorial(int n);

int main() {

    int n, x, t=0, i;
    scanf("%i %i", &n, &x);

    for(i=1; i<=n; i++) {
        t+=nCr(n,i);
    }
    printf("%i\n", abs(x-t));
    return 0;
}


int nCr(int n, int r) {
    int result;

    result = factorial(n)/(factorial(r)*factorial(n-r));

    return result;
}


int factorial(int n) {
    int c;
    int result = 1;

    for (c = 1; c <= n; c++)
        result = result*c;

    return result;
}
