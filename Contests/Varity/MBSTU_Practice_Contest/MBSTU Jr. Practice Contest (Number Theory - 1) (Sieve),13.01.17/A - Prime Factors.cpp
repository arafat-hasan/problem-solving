/***************************************************************
*   FILE NAME:  A - Prime Factors.cpp
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

#include <stdio.h>
#include <math.h>
int sieve(int n);

int prime[4294967296];

int main(){

	int i, cnt, n,j, sq,primelst[10000000];

	sieve(4294967296);
    scanf("%i", &n);
    int  fact[n][2];
    
    
    sq=sqrt(n);
    
    for(i=0;i<n;i++){
			if(primelst[i]>sq){
				cnt=primelst[i];
				break;
			}
	}
    
    
	for(i=0;i<cnt;i++){
			fact[i][0]=fact[i][1]=0;
	}
	
    for(i=0, j=0;i<cnt;i++){
		if(n%primelst[i]==0){
			fact[j][0]= primelst[i];
			while(n%primelst[i]==0){
				n/=primelst[i];
				fact[j][1]++;
			}
			j++;
		}
	}
		

	for(i=0;i<j;i++)
	printf("%i %i\n", fact[i][0],fact[i][1]);


return 0;

}




int sieve(int n){
	
	int i,j;
    double root=sqrt(n);
    
	prime[0]=prime[1]=1;
	
	for(i=4;i<n;i+=2)
		prime[i]=1;
	
    for(i=3; i<=root; i+=2){
        if(!prime[i])
			for(j=i+i; j<n; j+=i)
				prime[j]=1;
    }
    
    for(i=0, j=0; i<n; i++){
        if(prime[i]==0){
            primelst[j]=i;
            j++;
		}
    }
    return j;
    
}
