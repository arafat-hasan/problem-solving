/**************************************************************
*   FILE NAME:  Brick Game-11875.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   21 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
int main() {

int t, n, age[11], j = 0, i;
scanf("%i", &t);
while(j < t && scanf("%i", &n) ==1){
	j++;
	for(i = 0; i < n; i++){
		
		scanf("%i", & age[i]);
		
		}	
		
		printf("Case %i: %i\n",j, age[(n-1)/2] );
		
		
	}    
    return 0;
}
