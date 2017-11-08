/**********************************************************************
*   FILE NAME: Clock Hands-579.c
*
*   PURPOSE: Solve of Uva problem 579
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    11 Jul 2016    New             1.0         accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int h,m;
    int ans;
    while(scanf("%d %*c %2d",&h,&m)==2) {
        if(h==0&&m==0)
            break;
        ans=(h*5-m)*6;
        if (ans>=0)
            if(ans+0.5*m>180)
                printf("%.3f\n",360-ans-0.5*m);
            else
                printf("%.3f\n",ans+0.5*m);
        else {
            if(ans+0.5*m<-180)
                printf("%.3f\n",ans+0.5*m+360);
            else {
                if(ans+0.5*m>=0)
                    printf("%.3f\n",ans+0.5*m);
                else
                    printf("%.3f\n",-ans-0.5*m);
            }
        }
    }
    return 0;
}
