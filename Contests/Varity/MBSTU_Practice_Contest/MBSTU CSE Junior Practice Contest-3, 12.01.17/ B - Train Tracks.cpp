/***************************************************************
*   FILE NAME:  B - Train Tracks.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   12 Jan 16      New         1.0         not-Completed
*****************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	
	unsigned int t, arr[110]; unsigned char ch[200], flag,i,j, len;
	scanf("%i", &t);
	while(t--){
		

		for(i=0, j=0;i<100;i++){
			if(ch[i]=='M'){
				arr[j]= 1;
				j++;
			}
			
			if(ch[i]=='F'){
				arr[j]= 0;
				j++;
			}
		}	


		flag=1;

		for(i=1;i<j;i+=2){
	
			if(arr[i]+arr[i+1]!=1){
				flag=0;
				break;
			}
		}
		
		if(arr[0]+arr[j]!=1)
		flag=0;
		
		if(flag)
		printf("LOOP\n");
		else
		printf("NO lOOP");
		
		
	}

	return 0;
}
