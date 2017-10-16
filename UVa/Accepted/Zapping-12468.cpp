/**************************************************************
*   FILE NAME:  Zapping-12468.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   27 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>


int main() {

    int crr, des;


    while(scanf("%i %i", &crr, &des)==2) {

        if((crr < 0) || (des < 0)) {
            break;
        }

        if(des < crr) {
            des = des + crr;
            crr = des - crr;
            des = des - crr;
        }

        if((des-crr)>(100-des+crr))
            printf("%i\n", 100-des+crr);
        else
            printf("%i\n", des-crr);

    }

    return 0;
}
