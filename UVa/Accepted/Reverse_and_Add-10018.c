/************************************************************************
*   FILE NAME:	Reverse and Add-10018.c
*
*   PURPOSE:	Uva
*
*   @author:	Arafat Hasan
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Sep 2016    New             1.0         In-completed
*************************************************************************/

#include<stdio.h>
long long reverse,n;
int palindrome(void) {
    long long temp;
    temp = n;
    reverse = 0;
    while( temp != 0 ) {
        reverse = reverse * 10;
        reverse = reverse + temp%10;
        temp = temp/10;
    }
    if ( n == reverse )
        return 0;
    else
        return 1;
}


int main() {
    int count,t;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld",&n);
        count = 0;
        palindrome();
        do {
            count++;
            n+=reverse;
        } while(palindrome());
        printf("%d %lld\n",count,n);
    }
    return 0;
}
