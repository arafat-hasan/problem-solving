/**************************************************************
*   FILE NAME:  A_Change_in_Thermal_Unit-11984.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   21 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>

int main() {
    int testcase, j = 0;
    double c, f;
    scanf("%i", &testcase);

    while (j < testcase && scanf("%lf %lf", &c, &f) == 2) {
        j++;
        printf("Case %i: %.2lf\n", j, c + f/1.8);
    }
    return 0;
}
