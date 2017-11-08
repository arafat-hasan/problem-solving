/***********************************************************************
*   FILE NAME: Horror Dash-11799.cpp
*
*   PURPOSE: 
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         Completed, accepted
***********************************************************************/
#include <stdio.h>
#include <limits.h>
int main() {

    int t, n, max, s[101], i,j=0;
    scanf("%i", &t);
    while(j<t) {
        scanf("%i", &n);
        max=INT_MIN;
        for(i=0; i<n; i++) {
            scanf("%i", &s[i]);
            if(max<s[i])
                max=s[i];
        }
        j++;
        printf("Case %i: %i\n", j,max);

    }
    return 0;
}
