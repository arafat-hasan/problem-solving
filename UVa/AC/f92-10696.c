/***********************************************************************
*   FILE NAME: f92-10696.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    03 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int n;
    while(scanf("%d",&n)==1&&n!=0) {
        if(n>100)
            printf("f91(%d) = %d\n",n,n-10);
        else
            printf("f91(%d) = 91\n",n);
    }
    return 0;
}
