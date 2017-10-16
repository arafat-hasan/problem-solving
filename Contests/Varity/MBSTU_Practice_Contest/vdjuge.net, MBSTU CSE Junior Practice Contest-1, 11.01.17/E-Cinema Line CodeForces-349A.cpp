/***********************************************************************
*   FILE NAME: E-Cinema Line CodeForces-349A.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    11 Jun 2017    New             1.0         in-Completed,Not-Accepted
***********************************************************************/

#include <stdio.h>

int main() {

	int n, m[100010], cash=0, i, back, note25=0, note50=0, note100=0;
	scanf("%i", &n);
	for(i=0; i <  n; i++){
		scanf("%i", &m[i]);
		
		if(m[i]==25)
			note25++;
			
		else if(m[i]==50)
			note50++;
		else(m[i]==100)
			note100++;
			back= m[i] - 25;				
		if(m[i]>25){

			if(back>cash){
			printf("NO\n");
			return 0;
			}
		}
		
		
		tm100 = (note100*100)/back;
		back -= tm100;
		
				tm100 = (note100*100)/back;
		back -= tm100;
		
		
				tm100 = (note100*100)/back;
		back -= tm100;
		
		cash+=25;
	}
	printf("YES\n");
    return 0;
}
