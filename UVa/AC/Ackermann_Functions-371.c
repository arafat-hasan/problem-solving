/***************************************************************************************
*   FILE NAME:  Ackermann_Functions-371.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
* 	30 Sep 16		New			1.0			Accepted
**************************************************************************************/

#include <stdio.h>

int main(){

		long long a,i,j,L,H,S,V,temp,array[10000000]={0,4};//long long needed

		while(scanf("%lli %lli", &L, &H) == 2){

			if(!(L||H))
				break;

			S = 0;
			
			if(L > H){
				temp = H;
				H = L;
				L = temp;
			}

			printf("Between %lli and %lli, ", L, H);

			for(j = L; j <= H; j++){

				if(array[j]){
					i = array[j];
				}

				else{

					i=1;
					a=j;
				
					while(a > 1){
					
						i++;
						
						if(a % 2){
							a=(3 * a) + 1;
						}

						else{
							a = a / 2;
						}
						
					}
					
					array[j]=i;
					
				}
				
				if(i > S){
					S = i;
					V = j;
	
				}
				
			}
			
			printf("%lli generates the longest sequence of %lli values.\n", V,S-1);
			
		}

		return 0;
	}
