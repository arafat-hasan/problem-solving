/***************************************************************
*   FILE NAME:  A - Soroban.cpp
* 
*	LINK: http://codeforces.com/problemset/problem/363/A
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   13 Jan 16      New         1.0         Completed, AC
*****************************************************************/

#include <stdio.h>

int main() {

	long long  tmp, num;

	scanf("%lli", &num);
	
	if(num==0)
		printf("O-|-OOOO\n");	

	else
	while(num>0){
		tmp=num%10;
		num/=10;
		
		if(tmp==0)
			printf("O-|-OOOO\n");
		else if(tmp==1)
			printf("O-|O-OOO\n");
		else if(tmp==2)
			printf("O-|OO-OO\n");
		else if(tmp==3)
			printf("O-|OOO-O\n");
		else if(tmp==4)
			printf("O-|OOOO-\n");
		else if(tmp==5)
			printf("-O|-OOOO\n");
		else if(tmp==6)
			printf("-O|O-OOO\n");
		else if(tmp==7)
			printf("-O|OO-OO\n");
		else if(tmp==8)
			printf("-O|OOO-O\n");
		else if(tmp==9)
			printf("-O|OOOO-\n");
	}

	
	return 0;
}
