/***************************************************************************************
*   FILE NAME: Where is the Marble?-10474.c
*
*   PURPOSE: Solve of Uva problem p10474.
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*		21 June 16      New             0.0		Completed, not submitted
* 												wrong ans
* 		17 Nov 16						1.0		Corrected, Accepted
*****************************************************************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int i,m,q,j=0,k;
    while(scanf("%d %d",&m,&q)==2) {
        if(m==0&&q==0)
            break;
        j++;
        int w[m],Q[q];
        for(i=0; i<m; i++) {
            scanf("%d",&w[i]);
        }

        for(i=0; i<q; i++)
            scanf("%d",&Q[i]);

        sort(w, w+m);
        printf("CASE# %d:\n",j);
        for(i=0; i<q; i++) {
            for(k=0; k<m; k++) {
                if(w[k]==Q[i]) {
                    printf("%d found at %d\n",Q[i],k+1);
                    break;
                }

            }
            if(k==m) {
                printf("%d not found\n",Q[i]);
            }
        }
    }
    return 0;
}
