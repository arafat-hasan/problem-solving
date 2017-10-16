/**************************************************************
*   FILE NAME:  10.6.2-12578.cpp
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
#define PI 3.141592654
int main() {

    int t;
    double red, r, L;
    scanf("%i", &t);
    while(t--) {

        scanf("%lf", &L);
        r= L / 5;
        red = PI * r * r;
        printf("%.2lf %.2lf\n", red, (double)((6 * L * L) / 10) - red);

    }

    return  0;
}
