/***************************************************************
*   FILE NAME:  Digit Counting-1225.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   02 Nov 16      New         1.0         Completed, Accepted
*****************************************************************/
#include <stdio.h>

int main() {

    int t, n, count[10], i, temp;
    
    scanf("%i", &t);
    
    while(scanf("%i", &n)==1) {

        for(i=0; i<10; i++)
            count[i]=0;

        for(i=1; i <= n; i++) {
            temp = i;
            while(temp>0) {
                count[temp % 10]++;
                temp /= 10;
            }
        }

        for(i=0; i <= 8; i++)
            printf("%i ", count[i]);
            
        printf("%i\n", count[9]);
        
    }

    return 0;
}
