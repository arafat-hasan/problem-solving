/***************************************************************
*   FILE NAME:  Joana and the Odd Numbers.cpp
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
	long long n;
	while(scanf("%lli", &n)==1){
		n/=2;
		n++;
		printf("%lli\n", (((n*n)*2)-1)*3-6);
	}
    return 0;
}
