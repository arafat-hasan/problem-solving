/***************************************************************************************
*   FILE NAME:	Coprime Conundrum.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   04 Oct 16      New         1.0         Completed
**************************************************************************************/

#include <stdio.h>

long long array[10000000];
long long f(long long n);
int iscoprime(int num1, int num2);

int main(){

		long long i,n,count=0;


		for(i=0;i<10000000;i++)
			array[i]=-1;

		array[0] = 0;	array[1] = 0;	array[2] = 0;
		array[3] = 0;	array[4] = 0;	array[5] = 0;
		scanf("%lli",&n);
		
		for(i=6;i<=n;i++){
			count+=f(i);
		}
			
		printf("%lli",count);
			
		return 0;
		
	}


long long f(long long n){
	
		long long i,j,a,count=0;
		
		a=n/2;

	
		if(array[n]==-1){
			
			for(i=2;i<=a;i++){

				if(i*(i+1)>n)
					break;
				
				for(j=i+1;j<=a;j++){

					if(i*j>n)
						break;
					
					if(i*j==n){
						
						if(iscoprime(i,j)){
							
							count++;

						}
						
					}
					
				}

			}

			array[n]=count;
			
		}
		

		return array[n];

	}




int iscoprime(int num1, int num2) {

    int r = 0;
    int gcd = 0;
    int i;

    for(i = 1; (i <= num1) || (i <= num2) ; ++i) {

        if( (num1 % i == 0) && (num2 % i == 0)) {

            gcd = i;
        }
    }

    if ( gcd == 1 ) r = 1;
    return r;
    return 0;
}
