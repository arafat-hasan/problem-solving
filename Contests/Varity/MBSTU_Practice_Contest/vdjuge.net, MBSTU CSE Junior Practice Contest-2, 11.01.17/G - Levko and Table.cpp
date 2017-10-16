/***********************************************************************
*   FILE NAME: G - Levko and Table.cpp
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

	int n, k, i, j,kk;
	scanf("%i %i", &n, &k);
	kk=n;
	for(i = 0; i < n; i++){
		
		for(j=1; j<kk;j++){
			printf("0 ");
		}
		
		if(kk==n)
			printf("%i", k);
		else
			printf("%i ", k);
			
		for(j = kk+1; j < n;j++){
			printf("0 ");
		}
		
		if(kk!=n)
			printf("0");
		printf("\n");
		
		kk--;
		
	}
    return 0;
}

