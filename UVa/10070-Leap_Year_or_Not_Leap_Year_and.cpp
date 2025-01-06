/*******************************************************************************
*   FILE NAME:  Leap Year or Not Leap Year and ...-10070.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   17 Nov 16		New			1.0			Accepted
*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main ()
{
    long  long Flag, Mod4, Mod100, Mod400, Mod15, Mod55, I, Len, leap;
    char A[1000000];
    int pr = 0;

    while (scanf("%s", A) == 1) {

        if ( pr != 0 )
            printf("\n");
        pr = 1;

        leap = Flag = Mod4 = Mod100 = Mod400 = Mod15 = Mod55 = 0;

        Len = strlen (A);

        for (I=0; I< Len; I++) {

            Mod4	= ((Mod4	* 10) + (A[I]-'0')) % 4		;
            Mod100	= ((Mod100	* 10) + (A[I]-'0')) % 100	;
            Mod400	= ((Mod400	* 10) + (A[I]-'0')) % 400	;
            Mod15	= ((Mod15	* 10) + (A[I]-'0')) % 15	;
            Mod55	= ((Mod55	* 10) + (A[I]-'0')) % 55	;
        }

        if ((Mod4==0 && Mod100!=0) || Mod400==0) {
            printf("This is leap year.\n");
            leap = 1;
            Flag = 1;
        }

        if (Mod15==0) {
            printf("This is huluculu festival year.\n");
            Flag = 1;
        }

        if (leap==1 && Mod55==0)
            printf("This is bulukulu festival year.\n");

        if (Flag==0)
            printf("This is an ordinary year.\n");
    }
    return 0;
}
