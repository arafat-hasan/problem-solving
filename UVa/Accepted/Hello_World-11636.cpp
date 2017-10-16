/**************************************************************
*   FILE NAME:  Hello World-11636.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   26 Oct 16      New         1.0         Completed, Accepted
***************************************************************/
#include <stdio.h>

int main() {

    int n, i, j, paste;

    i = 0;
    while(++i) {

        scanf("%i", &n);
        if(n < 0)
            break;

        for(j=0, paste = 1; ; j++) {
            paste *= 2;
            if(paste > n) {
                paste /= 2;
                break;
            }
        }
        if(n - paste)
            printf("Case %i: %i\n", i, j+1);
        else
            printf("Case %i: %i\n", i, j);

    }



    return  0;
}
