/***********************************************************************
*   FILE NAME: E - The Primary Problem.cpp
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
int primelst[maxS];

//~ int IsPrime(int num) {
    //~ int i,root=sqrt(num);
    //~ if(num<2)
        //~ return 0;
    //~ if(num==2)
        //~ return 1;
    //~ if(num%2==0)
        //~ return 0;
    //~ for(i=3; i<=root; i+=2)
        //~ if(num%i==0)
            //~ return 0;
    //~ return 1;
//~ }



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
}

int main() {
    int n, h,i;
	sieve(maxS);
    while(scanf("%i", &n), n) {
		h=n/2;
        for(i=0;i<=h; i++) {
            if(primelst[i]==0&&primelst[n-i]==0) {
                printf("%i:\n%i+%i\n",n, i, n-i);
                h=0;
            }
        }

        if(h)
            printf("%i:\nNO WAY!\n", n);
    }

    return 0;
}
