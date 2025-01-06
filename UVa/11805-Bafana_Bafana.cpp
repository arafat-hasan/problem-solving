/**************************************************************
*   FILE NAME:  Bafana Bafana-11805.cpp
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

#include <stdio.h>

int main() {

    int player, position, pass, t, i=1;
    scanf("%i", &t);

    while(i <= t) {
        scanf("%i %i %i",&player, &position, &pass);

        if(pass>=0)
            pass=pass%player;

        if(position+pass>player)
            printf("Case %i: %i\n",i, pass+position-player);
        else
            printf("Case %i: %i\n",i, position+pass);

        i++;
    }
}
