/************************************************************************
*   FILE NAME:	Maximum Product-11059.cpp
*
*   PURPOSE:
*
*		@author:    Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    25 Oct 2016    New             1.0         Completed, Accepted
*************************************************************************/

#include<stdio.h>

int main() {

    long long int n,ar[20],max,p,cs=1,i,j;
    while(scanf("%lld",&n)==1) {
        max=0;
        for(i=0; i<n; i++)
            scanf("%lld",&ar[i]);
        for(i=0; i<n; i++) {
            p=1;
            for(j=i; j<n && p; j++) {
                p*=ar[j];
                if(p>max)
                    max=p;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",cs++,max);
    }
    return 0;
}


//~ #include <stdio.h>
//~ #include <limits.h>

//~ int main() {

    //~ long long n, d[20], i, j, k, p, t=1;


    //~ while(scanf("%lli", &n) == 1) {

        //~ for(i = 0; i < n; i++) scanf("%lli", &d[i]);
        //~ long long max = INT_MIN;

        //~ for(i=0; i < n; i++) {
            //~ for(j = n; j > 0; j--) {
                //~ p = 1;
                //~ for(k = i; k < j+i; k++) {
                    //~ if(k>=n)
                        //~ break;
                    //~ p *= d[k];
                    //~ if(p>max)
                        //~ max = p;
                //~ }
            //~ }
        //~ }
        //~ if(max<0)
			//~ max=0;
        
        //~ printf("Case #%lli: The maximum product is %lli.\n\n", t++, max);

    //~ }
    //~ return 0;
//~ }
