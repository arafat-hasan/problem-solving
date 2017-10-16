/**************************************************************
*   FILE NAME:  Decoding-11541.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------
*   25 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    int testcase, Case = 0, len, j, ch, fr, i;
    char str[201], tmp[18];
    scanf("%i", &testcase);
    while(Case < testcase && scanf("%s", str) == 1) {
		Case++;
        len = strlen(str);
        printf("Case %i: ", Case);
        for(i = 0; i < len; ) {
			
            ch = i;
            i++;
            j = 0;
            while(isdigit(str[i])) {
                tmp[j] = str[i];
                i++;
                j++;
            }
            tmp[j]='\0';
            fr = atoi(tmp);
            for(j = 0; j < fr; j++)
                printf("%c", str[ch]);

        }
printf("\n");

    }
    return 0;
}
