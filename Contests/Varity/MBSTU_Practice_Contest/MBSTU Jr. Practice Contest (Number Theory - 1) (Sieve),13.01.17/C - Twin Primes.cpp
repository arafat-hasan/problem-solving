/***************************************************************
*   FILE NAME:  C - Twin Primes.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   14 Jan 16      New         1.0         Completed
*****************************************************************/

#include<stdio.h>
#include<math.h>
#include<string.h>


int main()
{
    int i,j,root,t=1;
    long long int n=0;

    int N=20000000;
    char p[N];
    int tp[N];

    memset(p,1,N);

    p[0]=p[1]=0;
    root=sqrt(N);

    for(i=2; i<=root; i++)
        if(p[i]==1) {
            for(j=i+i; j<=N; j=j+i)
                p[j]=0;
        }

    for(i=3; i<N; i++) {
        if(p[i]==1 && p[i+2]==1) {
            tp[t++]=i;
        }
    }

    while(scanf("%lli",&n)==1) {
        printf("(%i, %i)\n",tp[n],tp[n]+2);
    }

    return 0;
}
