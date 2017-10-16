/***********************************************************************
*   FILE NAME: D - Group of Students.cpp
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

	int m, c[100], x, y, i, j, intr, beg;
	
	scanf("%i", &m);
	for(i = 0; i < m; i++){
		scanf("%i", &c[i]);
	}
		
	scanf("%i %i", &x, &y);
		
	for(i = 0; i < m; i++){
			
		intr=0; beg=0;
			
		for(j=0; j<i; j++){
			beg+=c[j];	
		}
			
		for(j=i; j<m; j++){
			intr+=c[j];
		}
			
		if((beg>=x&&beg<=y) && (intr>=x&&intr<=y)){
			printf("%i\n", i+1);
			return 0;
		}			
	}
		
	if(i==m)
	printf("0\n");
	
    return 0;
}
