/***********************************************************************
*   FILE NAME: Odd Sum-10783.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    03 Aug 2016    New             1.0         Completed,Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int a,b,t,sum,i=0;
    scanf("%d",&t);
    while(i<t) {
        i++;
        sum=0;
        scanf("%d %d",&a,&b);
        if(a%2==0)
            a++;
        for(; a<=b; a+=2)
            sum+=a;
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
