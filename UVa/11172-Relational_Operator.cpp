/**************************************************************
*   FILE NAME:  Relational Operator-11172.cpp
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
#define S(a, b) scanf("%i %i",&a, &b)
#define P(r) printf("%c\n",r)

int main() {

    int t, a, b;

    scanf("%i", &t);

    while(t--) {
        S(a, b);
        a  > b ? P('>') : a < b ? P('<') : P('=');
    }
    
    return 0;
}
