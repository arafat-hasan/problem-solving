/************************************************************************
*   FILE NAME: Peter's Smokes-10346.c
*
*   PURPOSE:    Uva
*
*   AUTHOR: Arafat Hasan
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Sep 2016    New             1.0         Completed,Accepted
*************************************************************************/

#include<stdio.h>
int q;
int coca(int n) {
    int e,k;
    e=n/q;//full
    k=n-e*q+e;
    if(n<q)
        return e;
    return e+coca(k);
}

int main() {
    int n;
    while(scanf("%d %d",&n,&q)==2)
        printf("%d\n",coca(n)+n);
    return 0;
}
