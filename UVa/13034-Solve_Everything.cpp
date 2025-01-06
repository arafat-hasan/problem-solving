/***********************************************************************
*   FILE NAME: Solve Everything :-)-13034.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    18 Nov 2016    New             1.0         completed,accepted
***********************************************************************/

#include <stdio.h>

int main() {

    int t, i, j = 0, n, flag;
    scanf("%i", &t);
    while(j<t) {
        flag = 1;
        j++;
        for(i = 0; i<13; i++) {
            scanf("%i", &n);
            if(n<1)
                flag = 0;
        }

        if(flag)
            printf("Set #%i: Yes\n", j);
        else
            printf("Set #%i: No\n", j);
    }

    return 0;
}
