/**************************************************************
*   FILE NAME:  Easy Problem from Rujia Liu-11991.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   23 Oct 16      New         1.0         Completed,Not-Accepted
***************************************************************/
#include <stdio.h>
#include <math.h>

int main() {

    int array[10000], m, k, v,  n, i, ans[10000][1000];
    while(scanf("%i %i" ,&n, &m) == 2) {
printf("sdfdg");
        for(i=0; i<n; i++) {
            scanf("%i", &array[i]);
        }

        for(i=0; i<10000; i++) {
            ans[i][0]=0;
        }

        for(i=0; i<n; i++) {
            ans[array[i]][    ans[   array[i]     ][0]+1  ]=i;
            ans[array[i]][0]++;

        }


        for(i=0; i<m; i++) {
            scanf("%i %i", &k, &v);

            if(k > ans[v][0])
                printf("0\n");
            else
                printf("%i\n", ans[v][k]);

        }

    }

    return 0;
}
