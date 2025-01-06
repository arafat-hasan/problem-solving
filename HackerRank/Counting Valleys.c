/***********************************************************************
*   FILE NAME: Counting Valleys.c
*
*   PURPOSE:    HackerRank Contest problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    26 Jul 2016    New             1.0         Completed
***********************************************************************/
#include<stdio.h>
int main() {
    int n,l=0,cnt=0,e=0;
    scanf("%d",&n);
    char i;
    for(; n>0; n--) {
        scanf(" %c",&i);
        if(i=='U')
            l++;
        else
            l--;
        if(l<0&&e==0) {
            cnt++;
            e=1;
        }
        if(l>=0&&e==1)
            e=0;
    }
    printf("%d",cnt);
    return 0;
}
