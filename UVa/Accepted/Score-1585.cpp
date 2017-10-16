/*****************************************************************************
*   FILE NAME:	Score-1585.cpp
*
*   PURPOSE:    Uva
*
*   WRITER: Md. Arafat Hasan Jenin
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    17 Nov 16      New             1.1         Newly written,Accepted
*
******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    
    int score, i, t, len, temp;
    char r[1000];
    scanf("%i", &t);
    while(t--){
        scanf("%s", r);
        len = strlen(r);
        score = 0;
        for(i= 0; i < len; i++){
            temp = 1;
            while(r[i] == 'O'){
            score += temp;
            temp++;
            i++;
            }
        }
        
        printf("%i\n", score);
    }
    return 0;
    
}
