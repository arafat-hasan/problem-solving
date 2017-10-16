/*****************************************************************************
*   FILE NAME:	B - Zapping .cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin, 1st year 2nd semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    15 Jan 16      New             1.0         Accepted
*
******************************************************************************/

#include <stdio.h>

int main() {

    int a,b;

    while(scanf("%i %i", &a, &b)==2 && a!=-1 && b!=-1) {

        if(a>b) {
            a=a+b;
            b=a-b;
            a=a-b;
        }

        if((b-a) > (a+100-b))
            printf("%i\n", (a+100-b));
        else
            printf("%i\n", b-a);
    }
    return 0;
}
