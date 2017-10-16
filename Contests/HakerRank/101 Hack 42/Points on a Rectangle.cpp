/***************************************************************************************
*   FILE NAME:  Points on a Rectangle.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   18 Oct 16      New         1.0         Completed,Accepted
**************************************************************************************/

#include <stdio.h>
#include <limits.h>

int main() {

    int q, n, x[10], y[10], i , maxx, maxy, minx, miny, flag;

    scanf("%i", &q);
    while(q--) {

        scanf("%i", &n);

        for(i = 0; i < n; i++) {
            scanf("%i %i", &x[i], &y[i]);
        }

        maxx = maxy = -INT_MAX;
        minx = miny = INT_MAX;

        for(i=0; i < n; i++) {

            if(x[i] > maxx) {
                maxx = x[i];
            }

            if(y[i] > maxy) {
                maxy = y[i];
            }

            if(x[i] < minx) {
                minx = x[i];
            }

            if(y[i]<miny) {
                miny = y[i];
            }
        }

        flag  = 1;
        for(i = 0; i < n; i++) {
            if(x[i]!=maxx && x[i]!=minx) {
                if(y[i] < maxy && y[i] > miny) {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
