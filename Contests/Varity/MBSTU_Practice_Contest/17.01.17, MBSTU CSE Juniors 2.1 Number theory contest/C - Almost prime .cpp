/***********************************************************************
*   FILE NAME: C - Almost prime .cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    17 Jan 2017    New             1.0         Completed
***********************************************************************/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#define maxS 1000000
int prime[100000], primelst[maxS];

void sieve(int n) {

    int i,j;
    double root=sqrt(n);

    primelst[0]=primelst[1]=1;

    for(i=4; i<n; i+=2)
        primelst[i]=1;

    for(i=3, j=0; i<=root; i+=2) {
        if(!primelst[i]) {
            for(j=i*i; j<n; j+=2*i)
                primelst[j]=1;
        }
    }


    for(i=0, j=0; i<n; i++) {
        if(primelst[i]==0) {
            prime[j++]=i;
        }
    }
}


int main() {
    int n, h,i, t;
    sieve(maxS);
    scanf("%i", &t);

    while(scanf("%i", &n), --t) {

        for(i=0; prime[i]<n; i++) {





        }


    }

    return 0;
}
