/***********************************************************************
*   FILE NAME: An_Interesting_Game-12751.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    04 Aug 2016    New             1.0         Completed,Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int n,k,x,t,i=1;
    scanf("%d",&t);
    while(i<=t) {
        scanf("%d %d %d",&n,&k,&x);
        printf("Case %d: %d\n",i,(n*(n+1))/2-((2*x+k-1)*k)/2);
        i++;
    }
    return 0;
}
