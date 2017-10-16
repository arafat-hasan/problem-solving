/***********************************************************************
*   FILE NAME:	Medians-10347.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    06 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
    double m1,m2,m3,a,t=0;
    while(t<1000&&scanf("%lf %lf %lf",&m1,&m2,&m3)==3) {
        t++;
        a=sqrt(((m1+m2+m3)/2)*(((m1+m2+m3)/2)-m1)*(((m1+m2+m3)/2)-m2)*(((m1+m2+m3)/2)-m3))*4/3;
        if(a>0)
            printf("%.3lf\n",a);
        else
            printf("-1.000\n");
    }
    return 0;
}
