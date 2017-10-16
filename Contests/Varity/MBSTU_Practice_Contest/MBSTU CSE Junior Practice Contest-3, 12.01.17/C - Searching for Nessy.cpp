/***************************************************************
*   FILE NAME:  C - Searching for Nessy.cpp
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

int main() {
	
	int t,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%i %i",&x,&y);
		printf("%i\n",(x/3)*(y/3));
	}

	return 0;
}
