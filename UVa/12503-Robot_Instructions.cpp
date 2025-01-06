/***********************************************************************
*   FILE NAME: Robot Instructions-12503.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    19 Nov 2016    New             1.0         Completed, Accepted
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int t, n[100], ans, ins, i;
    char ch[15];
    
    scanf("%i", &t);
    while(t-- && scanf("%i", &ins) == 1) {

        for(i = 0; i < ins; i++) {
            scanf(" %[^\n]", ch);
            if(ch[0] == 'R') {
                n[i] = 1;
            }
            else if(ch[0] == 'L') {
                n[i] = -1;
            }
            else {
                n[i] = n[atoi(ch+8)-1];
            }
        }
        
        ans = 0;
        for(i = 0; i < ins; i++)
            ans+=n[i];
            
        printf("%i\n", ans);

    }

    return 0;
}

