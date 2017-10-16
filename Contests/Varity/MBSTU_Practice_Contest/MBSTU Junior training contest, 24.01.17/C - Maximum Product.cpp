/***********************************************************************
*   FILE NAME: C - Maximum Product.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    24 Jan 17    New             1.0         Completed,Accepted
***********************************************************************/

#include <stdio.h>
#include <limits.h>

int main() {

    long long n, d[20], i, j, k, p, t=1;


    while(scanf("%lli", &n) == 1) {

        for(i = 0; i < n; i++) scanf("%lli", &d[i]);
        long long max = INT_MIN;

        for(i=0; i < n; i++) {
            for(j = n; j > 0; j--) {
                p = 1;
                for(k = i; k < j+i; k++) {
                    if(k>=n)
                        break;
                    p *= d[k];
                    if(p>max)
                        max = p;
                }
            }
        }
        if(max<0)
			max=0;
        
        printf("Case #%lli: The maximum product is %lli.\n\n", t++, max);

    }
    return 0;
}
