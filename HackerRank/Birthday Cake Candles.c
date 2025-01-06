/***********************************************************************
*   FILE NAME: Birthday Cake Candles.c
*
*   PURPOSE:    HackerRank Contest problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    26 Jul 2016    New             0.0         Completed
***********************************************************************/
#include<stdio.h>
int main() {
    int n,i,mx=0,cnt;
    scanf("%d",&n);
    for(; n>0; n--) {
        scanf("%d",&i);
        if(mx<i) {
            mx=i;
            cnt=0;
        }
        if(mx==i)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
