/**************************************************************
*   FILE NAME:  A - Count the D'z.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   17 Jan 16      New         1.0         Completed
***************************************************************/

#include <stdio.h>
#include <math.h>
#include <limits.h>

int divisor(long long n) {

    if(n==1)
        return 1;

    int sq = sqrt(n), count=0, i;

    for(i=1; i<=sq; i++) {
        if(n%i==0) {
            count+=2;
        }
    }

    if(sq*sq==n)
        count--;

    return count;
}

int main() {

    long long t, u, l, div, i, max, index;

    scanf("%lli", &t);

    while(t--) {

        max=INT_MIN;
        scanf("%lli %lli", &l, &u);
        for(i=l; i<=u; i++) {
            div=divisor(i);
            if(max<div) {
                max=div;
                index=i;
            }
        }
        printf("Between %lli and %lli, %lli has a maximum of %lli divisors.\n", l, u, index, max);

    }
    return 0;

}

