/***********************************************************************
*   FILE NAME: Destination Together less 3.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    06 Aug 2016    New             1.0         In-completed
***********************************************************************/

#include<stdio.h>
long long fact(int n){
long long i,fact=1;
for(i=1;i<=n;i++)
    fact*=i;
return fact;
}
int main() {
    int n,m,c,t;
    scanf("%d %d %d",&n,&m,&c);
    t=n+m-c-1;
    printf("%lld\n",fact(t));
    return 0;
}
