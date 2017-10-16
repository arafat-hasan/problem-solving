/**************************************************************
*   FILE NAME:  Cost Cutting-11727.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   27 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>

int main() {
	
    int t, a, b, c, i = 1;
    
    scanf("%i", &t);
    
    while(i <= t) {
		
        scanf("%i %i %i", &a, &b ,&c);
        
        if((a > b && b > c) || (a < b && b < c))
            printf("Case %i: %i\n", i, b);
        else if((b > a && a > c) || (b < a && a < c))
            printf("Case %i: %i\n", i, a);
        else
            printf("Case %i: %i\n", i, c);
            
        i++;
    }


    return 0;
}
