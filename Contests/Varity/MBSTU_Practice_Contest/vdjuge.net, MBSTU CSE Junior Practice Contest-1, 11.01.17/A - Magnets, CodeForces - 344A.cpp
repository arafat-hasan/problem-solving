/***********************************************************************
*   FILE NAME: A - Magnets, Codeforces - 344A.cpp
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

#include<stdio.h>
int main() {

	int n, m[100000], p=2, count=0, i;
	scanf("%i", &n);
	for(i=0; i <  n; i++){
		scanf("%i", &m[i]);
		if(m[i]!=p){
		count++;
		p=m[i];
		}
	}
	printf("%i\n", count);
    return 0;
}
