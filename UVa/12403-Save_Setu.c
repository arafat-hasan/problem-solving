/***********************************************************************
*   FILE NAME: Save Setu-12403.c
*
*   PURPOSE:	Uva
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    05 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int t;
    double ac=0,tk;
    char ch[7];
    scanf("%d",&t);
    while(t) {
        scanf("%s",ch);
        if(ch[0]=='d') {
            scanf("%lf",&tk);
            ac+=tk;
        } else
            printf("%.0lf\n",ac);
        t--;
    }
    return 0;
}
