/**************************************************************
*   FILE NAME:  Lumberjack Sequencing-11942.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   24 Oct 16      New         1.0         Completed, Accepted
***************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main() {

    int N, array[10], i;
    bool flag;

    scanf("%i", &N);
    printf("Lumberjacks:\n");

    while(N--) {

        for(i=0; i<10; i++) {
            scanf("%i", &array[i]);
        }

        flag=1;
        if(array[0]>array[1]) {
            for(i=1; i<10; i++) {
                if(array[i-1]<array[i]) {
                    flag =0;
                    break;
                }
            }
        }

        else {
            for(i=1; i<10; i++) {
                if(array[i-1]>array[i]) {
                    flag =0;
                    break;
                }
            }
        }

        if(flag)
            printf("Ordered\n");
        else
            printf("Unordered\n");
            
    }

    return 0;
}
