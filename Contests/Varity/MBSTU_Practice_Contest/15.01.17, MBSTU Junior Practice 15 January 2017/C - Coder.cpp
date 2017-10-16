/*****************************************************************************
*   FILE NAME:	C - Coder.cpp
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

    int n, i, j;
    scanf("%i", &n);

    if(n%2) {
        printf("%i\n", (int)(((n+1)/2)*(n)-((floor)(n/2))));
    }

    else {
        printf("%i\n", (n/2)*n);
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i%2) {
                if(j%2)
                    printf("C");
                else
                    printf(".");
            }
            else {
                if(j%2)
                    printf(".");
                else
                    printf("C");
            }

        }
        printf("\n");
    }

    return 0;
}
