/***********************************************************************
*   FILE NAME: Above Average-10370.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    06 Nov 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include <stdio.h>

int main() {

    int n, t, gr[1000], sum, avg,count, i;

    scanf("%i", &t);
    while(t--) {
        scanf("%d", &n);
        sum = 0;
        for(i=0; i<n; i++) {
            scanf("%i", &gr[i]);
            sum += gr[i];
        }

        avg = sum/n;
        count=0;
        for(i=0; i<n; i++) {
            if(gr[i]>avg)
                count++;
        }

        printf("%.3lf%c\n", (((float)count) * 100)/n, 37);
    }
    return 0;
}
