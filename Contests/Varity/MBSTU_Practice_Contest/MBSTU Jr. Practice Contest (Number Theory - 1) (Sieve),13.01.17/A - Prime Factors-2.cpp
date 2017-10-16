/***************************************************************
*   FILE NAME:  A - Prime Factors-2.cpp
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
int fact(int n);
#define max 1000000
int prime[max];


int main(){
	
	int n;
	while(scanf("%i", &n), n){
		fact(n);
	}
	return 0;
	
	
	}

int fact(int n){

	int i, cnt,j, sq, k;

    k=n;
    if(n<0)
		n=-n;
    int  fact[n][2];
    
    
    sq=sqrt(n);
    for(i=0; i<sq; i++){
		prime[i]=0;
    }
    sieve(sq);
	if(n==1){
		printf("1 = 1\n");
		return 0;
		}

    int primelst[max];

    for(i=0, j=0; i<n; i++){
        if(prime[i]==0){
            primelst[j]=i;
            j++;
		}
    }
    cnt=j;
    

	for(i=0;i<cnt;i++){
			fact[i][0]=fact[i][1]=0;
	}

    for(i=0, j=0;i<cnt;i++){//x 2 x xX
		if(n%primelst[i]==0){
			fact[j][0]= primelst[i];
			while(n%primelst[i]==0){
				n/=primelst[i];
				fact[j][1]++;
			}
			j++;
		}
	}


	if(j==0){
		printf("%i = 1 x %i\n", n, n);
		return 0;
		}

		
	printf("%i = ", k);
	if(k<0)
		printf("-1 x ");
	for(i=0;i<j;i++){

		printf("%i", fact[i][0]);
		if(fact[i][1]>1)
			printf(" ");
		//printf("#%i#\n", fact[i][1]);
		for(k=1;k<fact[i][1]-1;k++){
			printf("x %i ", fact[i][0]);
		}
		if(fact[i][1]>1	)
		printf("x %i", fact[i][0]);
		if(i<j-1)
			printf(" x ");
	}
	printf("\n");
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
    return 0;
    
}
