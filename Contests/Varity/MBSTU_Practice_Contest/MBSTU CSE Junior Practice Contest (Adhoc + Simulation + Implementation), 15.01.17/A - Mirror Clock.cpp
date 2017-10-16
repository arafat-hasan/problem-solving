/*****************************************************************************
*   FILE NAME:	A - Mirror Clock.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin, 1st year 2nd semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    15 Jan 16      New             1.0         Newly written, Accepted
*
******************************************************************************/

#include <stdio.h>

int main() {
    int t,h,m;
    scanf("%d",&t);
    while(t) {
        scanf("%d%*c%d",&h,&m);

        if(h>=9&&h<=12&&m==0) {
            if(h==9)
                h=3;
            else if(h==10)
                h=2;
            else if(h==11)
                h=1;
        }
        else if(h>=9&&h<=12) {
            if(h==9)
                h=2;
            else if(h==10)
                h=1;
            else if(h==11)
                h=12;
            else if(h==12)
                h=11;
            m=60-m;
        }

        else if(h>=6&&h<9&&m==0) {
            if(h==7)
                h=5;
            else if(h==8)
                h=4;
        }
        else if(h>=6&&h<9) {
            if(h==7)
                h=4;
            else if(h==8)
                h=3;
            else if(h==6)
                h=5;
            m=60-m;
        }


        else if(h>=1&&h<=3&&m==0) {
            if(h==1)
                h=11;
            else if(h==2)
                h=10;
            else if(h==3)
                h=9;
        }
        else if(h>=1&&h<=3) {
            if(h==1)
                h=10;
            else if(h==2)
                h=9;
            else if(h==3)
                h=8;
            m=60-m;
        }



        else if(h>3&&h<6&&m==0) {
            if(h==4)
                h=8;
            else if(h==5)
                h=7;
        }
        else if(h>3&&h<6) {
            if(h==4)
                h=7;
            else if(h==5)
                h=6;
            m=60-m;
        }

        printf("%02i:%02i\n", h, m);

        t--;
    }

    return 0;
}
