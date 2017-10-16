/***********************************************************************
*   FILE NAME: A. Awesome Childhood.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL: 
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    20 Jan 2017    New             1.0         Completed, Accepted
***********************************************************************/


#include <iostream>
using namespace std;

int main() {
    long long  t, n, i=0;
    scanf("%lli", &t);
    while(i<t && scanf("%lli", &n)) {
        printf("Case %lli: %lli\n", ++i, (n+2)/2-1);
    }

    return 0;
}
