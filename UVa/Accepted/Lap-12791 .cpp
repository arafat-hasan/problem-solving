/*****************************************************************************
*   FILE NAME:	Lap-12791 .cpp
* 
*	LINK: https://uva.onlinejudge.org/external/127/12791.pdf
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
    float f, l;
    while(scanf("%f %f", &f, &l)==2){  
		  printf("%.0f\n", (ceil)((1/(1/f-1/l))/f));
		}
    
    return 0;
}

