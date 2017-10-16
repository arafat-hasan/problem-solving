/************************************************************************
*   FILE NAME:	The Decoder-458.cpp
*
*   PURPOSE:
*
*   @author:    Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    11 Oct 2016    New             1.0         Completed,  Accepted
*************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <string.h>

int main() {
    int i, len;
    char str[500];
    while( scanf(" %[^\n]", str)==1) {

        len = strlen(str);

        for(i = 0; i < len; i++) {
            str[i] -= 7;

        }
        
        printf("%s\n",str);
        
    }
    
    return 0;
}
