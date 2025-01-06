/***************************************************************
*   FILE NAME:  A. Gotta Catch Em' All!.cpp
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
#include <limits.h>

int main() {
	
	char str[1000001];
	int count[7], len, i, min; 
	
	scanf("%s", str);
	len=strlen(str);
	
	for(i = 0; i < len; i++){
		
		//Bulbasaur
		
		/*
		 * B=0, u=1, l=2, b=3, a=4, s=5, r=6,
		 * B 1
		 * u 2
		 * l 1
		 * b 1
		 * a 2
		 * s 1
		 * r 1
		 * 
		 * 
		 * */
		
		if(str[i]=='B')
			count[0]++;
		else if(str[i]=='u')
			count[1]++;
		else if(str[i]=='l')
			count[2]++;
		else if(str[i]=='b')
			count[3]++;
		else if(str[i]=='a')
			count[4]++;
		else if(str[i]=='s')
			count[5]++;
		else if(str[i]=='r')
			count[6]++;
		
		}
		
		count[1]/=2;
		count[4]/=2;
		
		min=INT_MAX;
		
		for(i=0; i< 7;i++){
			if(count[i]<min){
				min=count[i];
			}
		}
		
		if(min==0)
			printf("0\n");
		else
			printf("%i\n", min);


	return 0;
}
