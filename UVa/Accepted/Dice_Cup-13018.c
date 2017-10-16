/***********************************************************************
*   FILE NAME: Dice Cup-13018.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    04 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int d1,d2,mx,i,j,t=0;
    while(scanf("%d %d",&d1,&d2)==2) {
        mx=0;
        int temp[d1+d2-1];
        for(i=0; i<d1+d2-1; i++)
            temp[i]=0;
        for(j=1; j<=d1; j++)
            for(i=1; i<=d2; i++) {
                temp[j+i-2]+=1;
            }
        for(i=0; i<d1+d2-1; i++)
            if(mx<temp[i])
                mx=temp[i];
        if(t!=0)
            printf("\n");
        for(i=0; i<d1+d2-1; i++)
            if(mx==temp[i])
                printf("%d\n",i+2);
        t++;
    }
    return 0;
}
