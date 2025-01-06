/**************************************************************
*   FILE NAME:  Throwing cards away II-10940.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   27 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include<stdio.h>
#include<math.h>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d\n",a)

int main() {

    int n, p;

    while(S(n)==1) {

        if(n==0) break;

        p = (int) pow(2, (int)((log (n))/(log (2.0))));

		p == n ? P(n) : P(2 * (n - p));
		
    }

    return 0;
}
