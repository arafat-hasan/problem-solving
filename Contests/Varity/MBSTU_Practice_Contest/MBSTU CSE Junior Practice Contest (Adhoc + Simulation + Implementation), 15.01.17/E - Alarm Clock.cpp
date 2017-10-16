/*****************************************************************************
*   FILE NAME:	E - Alarm Clock.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin, 1st year 2nd semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    15 Jan 16      New             1.0         Newly written, Accepted
*
******************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    
    int h1, m1, h2, m2;
    
    while(scanf("%i %i %i %i", &h1, &m1, &h2, &m2) ==4){
		
		if(!(h1||h2||m1||m2))
			break;
			
		if((h2<h1)||((h2==h1)&&(m2<m1)))
			h2+=24;
			
		printf("%i\n", ((h2-h1)*60)-m1+m2);
	}
    
    return 0;
}

