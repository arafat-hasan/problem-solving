/*****************************************************************************
*   FILE NAME:	H(n)-11526.c
*
*   PURPOSE:    Uva
*
*   WRITER: Md. Arafat Hasan Jenin, 1st year 1st semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    06 Sep 16      New             1.1         Newly written,Accepted
*
******************************************************************************/

#include <stdio.h>
#include <math.h>

long long H(long long n) {

    long long sum = 0, sqr, step = 0, i;
    sqr = sqrt(n);
    for(i = 1; i <= sqr; i = i + 1) {
        step += n/i - n/(i+1);
        sum += i * (n/i - n/(i+1));
    }
    step = n - step;
for(i = 1; i <= step; i++){
	sum += n/i;
	}
    return sum;
}

int main() {
    long long n,t;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        printf("%lld\n",H(n));
    }
    return 0;
}
