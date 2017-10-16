/***************************************************************
*   FILE NAME:  A. PolandBall and Hypothesis.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   15 Jan 16      New         1.0         Completed
*****************************************************************/

#include <stdio.h>
#include <math.h>
int isprime(int n);

int main() {


    int n, i;

    scanf("%i", &n);

    for(i = 1;; i++) {
        if(!isprime((n*i)+1)) {
            printf("%i\n", i);
            return 0;
        }
    }

    return  0;
}



int isprime(int n) {

    int i,root=(int)(sqrt(n));

    if(n<2)
        return 0;

    if(n==2)
        return 1;

    if(n%2==0)
        return 0;

    for(i=3; i<=root; i+=2)
        if(n%i==0)
            return 0;

    return 1;
}
