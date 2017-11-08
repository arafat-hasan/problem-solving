/****************************************************************************
*   FILE NAME: Light, more light-10110.c
* 
*	LINK: https://uva.onlinejudge.org/external/101/10110.pdf
*
*   PURPOSE: Solve of Uva problem 10110.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    23 June 16      New             1.0		Completed, AC
*******************************************************************************/


/*
* There are a few things you should immediately notice:
*
*	1. Once Mabu has done his nth walk, the nth switch is never toggled again.
*	2. The answer is yes iff the nth switch is toggled an odd number of times
*		(otherwise, for each time it is turned on, it gets turned off, and is
*		thus off in the end).
*	3. The nth switch is toggled once for each factor of n.
*
* With this in mind, how can we tell if a number has an even or odd number of factors?
* For every factor n has below sqrt(n) it has one above sqrt(n). This suggests that
* unless n is a perfect square, it has an even number of factors. So, the problem
* boils down to deciding if n is a perfect square or not. Use your favorite math
* libraries to find the answer. 
*/

#include <stdio.h>
#include <math.h>
int main(){
	
	unsigned int l;
	double t;
	while(scanf("%ui",&l)==1){
		
		if(l==0)
			break;
			
		t=sqrt(l);
    
		if(ceil(t)==t)
			printf("yes\n");
		else
			printf("no\n");
		
	}

	return 0;

}
