/*******************************************************************
*   FILE NAME:  GCD LCM-11388.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    02 Nov 2016    New             1.0         Completed,Accepted
*******************************************************************/

#include <stdio.h>
int gcd(int a, int b) ;
int lcm(int a,int b);

int main() {

    int a,b, t;
    scanf("%i", &t);

    while(t-- &&scanf("%i %i", &a, &b)) {

        if(gcd(a, b) == a && lcm(a, b) == b)
            printf("%i %i\n", a, b);
        else
            printf("-1\n");

    }

    return 0;
}


int gcd(int a, int b)  {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int lcm(int a,int b) {

    int temp = a;

    while(1) {
        if(temp % b == 0 && temp % a == 0)
            break;
        temp++;
    }

    return temp;
}
