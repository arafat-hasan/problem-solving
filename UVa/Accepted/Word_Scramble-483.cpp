/**************************************************************
*   FILE NAME:  Word Scramble-483.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   21 Nov 16      New         1.0         Completed, Accepted
***************************************************************/
#include <stdio.h>
#include <string.h>

int main() {

    int i, j, len;
    char str[1000];

    while(scanf(" %[^\n]", str) == 1) {

        len = strlen(str);
        for(i = 0; i <= len; i++) {
            if(str[i] == ' ') {
                for(j = i-1; j >= 0; j--) {
                    if(str[j] == ' ')
                        break;
                    printf("%c", str[j]);
                }
                printf(" ");
            }


            else if(str[i] == '\0') {
                for(j = i-1; j >= 0; j--) {
                    if(str[j] == ' ')
                        break;
                    printf("%c", str[j]);
                }
                printf("\n");
            }


        }
    }

    return 0;
}
