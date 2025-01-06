/***********************************************************************
*   FILE NAME: Jesse and Profit.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    07 Aug 2016    New             1.0        Completed
***********************************************************************/

#include<stdio.h>
int main() {
    int d,k;
    long long n,b,s,i,j;
    scanf("%lld %d",&n,&d);
    long long N[n],D[d],min;
    for(i=0; i<n; i++)
        scanf("%lld",&N[i]);
    for(i=0; i<d; i++)
        scanf("%lld",&D[i]);
    for(k=0; k<d; k++) {
        min=n+5;
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(N[j]-N[i]==D[k])
                    if(min>j-i) {
                        min=j-i;
                        b=i;
                        s=j;
                    }
        if(min<n+5)
            printf("%lld %lld\n",b+1,s+1);
        else
            printf("-1\n");
    }
    return 0;
}
