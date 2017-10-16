/***************************************************************
*   FILE NAME:  Feynman-12149.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   23 Oct 16      	New         1.0         Completed,Accepted
****************************************************************/
#include <stdio.h>

int main() {
	
    int array[100], i, sum, n;

    while(scanf("%i", &n)==1) {
        if(n == 0)
            break;
            
        sum = 0;
        array[0] = 0;
        for(i= 1; i <= 100; i++) {
            array[i] = array[i-1] + i;
        }

        for(i=0; i<=n; i++) {
            sum+=array[i];
        }
        
        printf("%i\n", (sum * 2) - array[n]);
    }

    return 0;
}
