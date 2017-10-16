/************************************************************************
*   FILE NAME:	Triangle Wave-488.cpp
*
*   PURPOSE:
*
*   @author:    Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    11 Oct 2016    New             1.0         Completed, Accepted
*************************************************************************/

#include<stdio.h>
#include<ctype.h>

int main() {

    int amp, fr, i, j, flag, t;

    scanf("%i", &t);

    while(t--) {

        scanf("%i %i", &amp, &fr);

        while(fr--) {

            flag = 0;

            for(i = 1; i <= amp; ) {
                for(j = 1; j <= i; j++) {
                    printf("%i", i);

                }

                printf("\n");

                if(i == amp) {
                    flag = 1;
                }

                if(flag)
                    i--;
                else
                    i++;

                if(i == 0) {
                    break;

                }

            }
            if(t || fr)
                printf("\n");

        }
    }
    return 0;
}
