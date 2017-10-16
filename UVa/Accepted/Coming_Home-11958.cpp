/***********************************************************************
*   FILE NAME: Coming Home-11958.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    03 Nov 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include <stdio.h>
#include <limits.h>
int main() {

    int t, k,  i,j=0;
    long double elapsed_time[100],crr_time[1][2], dpr_time[100][2], jt[100],min;

    scanf("%i", &t);
    while(j < t && scanf("%i%Lf%*c%Lf", &k, &crr_time[0][0], &crr_time[0][1]) == 3) {

        i = 0;
        while(i<k) {
            scanf("%Lf%*c%Lf%Lf", &dpr_time[i][0], &dpr_time[i][1], &jt[i]);
            if((dpr_time[i][0] < crr_time[0][0]) || ((dpr_time[i][0] == crr_time[0][0]) && (dpr_time[i][1] < crr_time[0][1])))
                dpr_time[i][0] +=24;

            i++;
        }

        min = LONG_MAX;
        for(i = 0; i < k; i++) {

            if(dpr_time[i][1] < crr_time[0][1]) {
                elapsed_time[i] = (dpr_time[i][0] - crr_time[0][0] - 1) * 60 + (dpr_time[i][1] - crr_time[0][1] + 60) + jt[i];
            }

            else {
                elapsed_time[i] = (dpr_time[i][0] - crr_time[0][0]) * 60 + (dpr_time[i][1] - crr_time[0][1]) + jt[i];
            }

            if(elapsed_time[i] < min)
                min = elapsed_time[i];
        }

        j++;
        printf("Case %i: %.0Lf\n", j,min);
    }

    return 0;
}
