/***********************************************************************
*   FILE NAME: TEX Quotes-272.cpp
*
*   PURPOSE: Solve of Uva problem p537.
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         Completed, Accepted
***********************************************************************/
#include <stdio.h>
#include <string.h>

int main() {

    int i=0, len,c;
    char str[100000],ch;
    while(scanf("%c", &ch) == 1) {
        str[i]=ch;
        i++;
    }
    len = i;
    str[len] = '\0';
    c=0;
    for(i=0; i < len; i++) {

        if(str[i] == '\"') {
            if(c){
                
            printf("''");
                c=0;
                
            }
            else{
            printf("``");
                c=1;
            }
            }
            else
            printf("%c", str[i]);


     
}

                return 0;
            }
