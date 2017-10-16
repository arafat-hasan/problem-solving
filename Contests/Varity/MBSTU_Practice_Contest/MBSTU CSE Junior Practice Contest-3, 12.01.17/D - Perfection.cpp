/***************************************************************
*   FILE NAME:  D - Perfection.cpp
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
	
	int n, i, sum;
	
	printf("PERFECTION OUTPUT\n");
	
	while (scanf("%d", &n), n) {
		printf("%5d  ", n);
		sum=0;
		
		for (i=1;i<n;i++) {
			if (n%i == 0)
				sum+= i;
			if (sum>n) {
				printf("ABUNDANT\n");
				break;
			}
		}

		if(sum == n)
			printf("PERFECT\n");
		else if(sum<n)
			printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}
