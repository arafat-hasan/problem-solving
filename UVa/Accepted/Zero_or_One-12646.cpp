/**************************************************************
*   FILE NAME:  Zero or One-12646.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   26 Oct 16      New         1.0         Completed, Accepted
***************************************************************/

#include <stdio.h>

int main() {

    int a, b, c;

    while(scanf("%i %i %i", &a, &b, &c) == 3) {

        if(a == b && b == c)
            printf("*\n");

        else if(a == b)
            printf("C\n");

        else if(b == c)
            printf("A\n");

        else
            printf("B\n");

    }

    return  0;
}
