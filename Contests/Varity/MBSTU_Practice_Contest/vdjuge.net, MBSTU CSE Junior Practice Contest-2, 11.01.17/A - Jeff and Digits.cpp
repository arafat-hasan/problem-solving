/***********************************************************************
*   FILE NAME: A - Jeff and Digits.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    11 Jun 2017    New             1.0         Completed,Accepted
***********************************************************************/

#include <stdio.h>

int main() {

	long long n, a, a5=0, a0=0, i, num5;
	scanf("%lli", &n);
	
	for(i=0; i < n; i++){
		scanf("%lli", &a);
		if(a==5)
			a5++;
		else
			a0++;
	}

	num5=a5-(a5%9);
	
	
	if(a5>=9 && a0!=0){
		for(i=0; i<num5;i++){
			printf("5");
		}
		for(i=0;i<a0;i++){
			printf("0");
		}
		printf("\n");	
	}
		
	else if(a0!=0)
		printf("0\n");
		
	else
		printf("-1\n");
		
    return 0;
}

