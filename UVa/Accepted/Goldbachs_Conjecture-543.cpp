/**************************************************************
*   FILE NAME:  Goldbach's Conjecture-543.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   26 Oct 16      New         1.0         Completed, Accepted
***************************************************************/
#include <stdio.h>
#include <math.h>
int isprime(int n);

int main() {
    int i, Half, n;

    while(scanf("%i", &n) == 1) {

        if(n == 0)
            break;
        Half = n / 2;

        for(i = 2; i< Half; i++) {
            if(isprime(i)) {
                if(isprime(n-i))
                    break;
            }
        }

        printf("%i = %i + %i\n", n, i, n-i);

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
