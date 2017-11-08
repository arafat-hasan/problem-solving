/***************************************************************************************
*   FILE NAME:  Sum vs XOR.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   04 Oct 16      New         1.0         Completed,Accepted
**************************************************************************************/
#include <stdio.h>

int main(){

		long long i,n,count=0;
		
		scanf("%lli", &n);
		
		for(i=0;i<=n;i++){
			
			if((n + i) == (n ^ i))
				count++;

			}
			
		printf("%lli", count);
			
		return 0;
	}
