/***************************************************************
*   FILE NAME:  E - Valera and Plates.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   13 Jan 16      New         1.0         not-Completed
*****************************************************************/

#include <stdio.h>

int main() {
	
	int n, p, b, i;
	
	scanf("%i %i %i", &n, &b, &p);
	int day[n], count=0;;
	for(i=0;i<n;i++)
		scanf("%i", &day[i]);
	
	
	for(i=0;i<n;i++){
		if(day[i]==1){
			if(b>0)
				b--;
			else
				count++;
		}
		
		else{
			if(p>0)
				p--;
			else if(b>0)
				b--;
			else
				count++;
		}
	}
	
	printf("%i\n", count);
	
	return 0;
}
