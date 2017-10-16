/***********************************************************************
*   FILE NAME: Another Combination Problem-13035.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    18 Nov 2016    New             1.0         Not-completed
************************************************************************/

#include <stdio.h>
//~ long long nPr(long long n, long long r);
//~ long long nCr(long long n, long long r);
//~ long long factorial(long long n);
//~ long long com(long long n);

int main() {

    long long t, j = 0, n, i, k, sum[10000000], l;
    scanf("%lli", &t);
    sum[0] = 0;
    for(i = 1, k=1, l = 2; i<=9999999; i++, k++, l++) {
        sum[i] = sum[i-1]+(l*k)% 1000000007;

    }
    while(j<t) {
        j++;
        scanf("%lli", &n);

        printf("Case %lli: %lli\n", j, sum[n]);
    }

    return 0;
}

//~ long long nCr(long long n, long long r) {
//~ long result;

//~ result = factorial(n)/(factorial(r)*factorial(n-r));

//~ return result;
//~ }

//~ long long nPr(long long n, long long r) {
//~ long result;

//~ result = factorial(n)/factorial(n-r);

//~ return result;
//~ }

//~ long long factorial(long long n) {
//~ long long c;
//~ long result = 1;

//~ for (c = 1; c <= n; c++)
//~ result = result*c;

//~ return result;
//~ }


//~ long long com(long long n){

//~ return (n*(nCr(n+1,2))*2) % 1000000007;




//~ }
