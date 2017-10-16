/***************************************************************************************
*   FILE NAME:  Blind Sorting-11714.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
* 	30 Sep 16		New			1.0			Accepted
**************************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    long long n;

    while(scanf("%lli",&n)==1)
        printf("%lli\n",(n-1)+(int)log2(n-1));

    return 0;
}

