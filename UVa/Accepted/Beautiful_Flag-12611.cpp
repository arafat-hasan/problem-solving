/***********************************************************************
*   FILE NAME: Beautiful Flag-12611.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    26 Nov 2016    New             1.0         completed,accepted
***********************************************************************/\
#include <stdio.h>

int main() {

    int testcase, r, j=0;
    scanf("%i", &testcase);
    while(j < testcase && scanf("%i", &r) == 1) {
        j++;
        printf("Case %i:\n", j);
        printf("%.0f %.0f\n",-((float)9/4) * r, ((float)3/2) * r);
        printf("%.0f %.0f\n",((float)11/4) * r, ((float)3/2) * r);
        printf("%.0f %.0f\n",((float)11/4) * r, -((float)3/2) * r);
        printf("%.0f %.0f\n",-((float)9/4) * r, -((float)3/2) * r);
    }

    return 0;
}
