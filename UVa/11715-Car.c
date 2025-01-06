/************************************************************************
*   FILE NAME:	Car-11715.c
*
*   PURPOSE:	Uva
*
*   @author:	Arafat Hasan
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    11 Sep 2016    New             1.0         Completed, Accepted
*************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    int i,t=0;
    while(scanf("%d",&i)==1) {

        if(i==0)
            break;
        t++;

        scanf("%lf %lf %lf", &a, &b, &c);
        if(i==1) {
            printf("Case %d: %.3lf %.3lf\n",t,((a+b)/2)*c,(b-a)/c);
        }

        else if(i==2) {
            printf("Case %d: %.3lf %.3lf\n",t,(b*b-a*a)/(2*c),(b-a)/c);
        }

        else if(i==3) {
            printf("Case %d: %.3lf %.3lf\n",t, sqrt(a*a+2*b*c), (sqrt(a*a+2*b*c)-a)/b);
        }

        else {
            printf("Case %d: %.3lf %.3lf\n",t, sqrt(a*a-2*b*c), (a-sqrt(a*a-2*b*c))/b);
        }



    }
    return 0;
}
