/***************************************************************
*   FILE NAME:  B. Frodo and pillows.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   15 Jan 16      New         1.0         Completed
*****************************************************************/

#include <stdio.h>

int main() {

    int n, m, k;
    
    while(scanf("%i %i %i", &n, &m, &k)==3){

    if(n==m)
        printf("1\n");
    else if(k*k<m)
        printf("#%i\n", (m/n)+2);
    else
        printf("%i\n", (m/n)+1);

}
    return  0;
}
