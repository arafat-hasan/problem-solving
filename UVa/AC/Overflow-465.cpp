/************************************************************************
*   FILE NAME:	Overflow-465.cpp
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

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {

    //9999999999999999999999
    char f[1000], o, s[1000];


    while(scanf("%s %c %s", f, &o, s) == 3) {

        printf("%s %c %s\n", f, o, s);

        if(o == '+') {
            if(atoll(f) > INT_MAX || atoll(s) > INT_MAX) {

                if(atoll(f) > INT_MAX ) {
                    printf("first number too big\n");
                }

                if(atoll(s) > INT_MAX ) {
                    printf("second number too big\n");
                }
                printf("result too big\n");

            }

            else if(atoll(f) + atoll(s) > INT_MAX) {

                printf("result too big\n");

            }


        }

        else {

            if(atoll(f) > INT_MAX || atoll(s) > INT_MAX) {

                if(atoll(f) > INT_MAX ) {
                    printf("first number too big\n");
                }

                if(atoll(s) > INT_MAX ) {
                    printf("second number too big\n");
                }
                if(atoll(s) &&  atoll(f))
                    printf("result too big\n");
            }

            else if(atoll(f) * atoll(s) > INT_MAX) {

                printf("result too big\n");

            }

        }

    }


    return 0;
}
