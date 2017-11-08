/***************************************************************************************
*   FILE NAME:	Apple and Orange.cpp
*
*   PURPOSE:	
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   14 Oct 16      New         1.0         Completed,Accepted
**************************************************************************************/

#include<stdio.h>
int main() {

    int a, b, s, t, n, m, i, count_O = 0, count_A = 0;
    scanf("%i %i %i %i %i %i", &s, &t, &a, &b, &m, &n);
    int apple[m], orange[n];


    for(i=0; i<m; i++) {
        scanf("%i", &apple[i]);
        apple[i]+=a;
        if((apple[i]>=s) && (apple[i])<=t)
            count_A++;
    }

    for(i=0; i<n; i++) {
        scanf("%i", &orange[i]);
        orange[i]+=b;
        if((orange[i]>=s) && (orange[i])<=t)
            count_O++;
    }
    printf("%i\n%i\n", count_A, count_O);

    return 0;
}

