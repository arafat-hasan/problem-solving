/***************************************************************
*   FILE NAME:  Goldbach's Conjecture (II)-686.cpp
* 
*	LINK: https://uva.onlinejudge.org/external/6/686.pdf
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

/*#include <stdio.h>
#include <math.h>

void sieve(int n);
int prime[1000003];

int main() {
	
    int i, Half, n;

    while(scanf("%i", &n) == 1) {

        if(n == 0)
            break;

		sieve(1000001);
		Half = n / 2;
        for(i = 2; i< Half; i++) {
            if(!prime[i]) {
                if(!prime[n-i])
                    break;
            }
        }

        printf("%i = %i + %i\n", n, i, n-i);

    }
    return  0;
}


void sieve(int n){
	
	int i,j;
    double root=sqrt(n);
    
	prime[0]=prime[1]=1;
	
	for(i=2;i<n;i+=2)
		prime[i]=1;
	
    for(i=3; i<=root; i+=2){
        if(!prime[i])
			for(j=i+i; j<n; j+=i)
				prime[j]=1;
    }
}*/



#include <stdio.h>
#include <math.h>
int isprime(int n);

int main() {
    int i, Half, n, count;

    while(scanf("%i", &n) == 1) {

        if(n == 0)
            break;
        Half = n / 2;
		count=0;
        for(i = 2; i <= Half; i++) {
            if(isprime(i)) {
                if(isprime(n-i))
                    count++;
            }
        }

        printf("%i\n", count);

    }
    return  0;
}



int isprime(int n) {

    int i,root=(int)(sqrt(n));

    if(n<2)
        return 0;

    if(n==2)
        return 1;

    if(n%2==0)
        return 0;

    for(i=3; i<=root; i+=2)
        if(n%i==0)
            return 0;

    return 1;
}
