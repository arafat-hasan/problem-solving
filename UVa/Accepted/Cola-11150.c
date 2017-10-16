/***********************************************************************
*   FILE NAME: Cola-11150.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    27 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>

int cola(int n) {
    if(n<3)
        return 0;
    if(n%3==0)
        return n/3+cola(n/3);
    int y;
    y=n/3;
    if(n%3==1)
        return y+cola(y+1);
    return y+cola(y+2);
}

int main() {
    int n;
    while(scanf("%d", &n)==1) {
        printf("%d\n",cola(n+1)+n);
    }
    return 0;
}
