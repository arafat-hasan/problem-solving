/***************************************************************************************
*   FILE NAME:  Project Euler 162: Hexadecimal numbers.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   26 Oct 16      New         1.0         Not Completed
**************************************************************************************/


#include <stdio.h>
#include <math.h>
long long factorial(long long n);
long long nCr(long long n, long long r);
long long nPr(long long n, long long r);

int main() {
    long long ans, n;
    scanf("%lli", &n);
    ans = (((nCr(n,3)*6)-(nCr(n-1,2)))*((n-1)*(long long)(pow(n-3,16))));
    printf("%lli\n", ans);
    return 0;
}



long long factorial(long long n) {
   return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}


long long nCr(long long n, long long r) {
   return (nPr(n,r) / factorial(r));
   //return factorial(n) / factorial(r) / factorial(n-r));
}


long long nPr(long long n, long long r) {
   return (factorial(n) / factorial(n-r));
}
