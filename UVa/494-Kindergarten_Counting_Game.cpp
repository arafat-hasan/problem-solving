/************************************************************************
*   FILE NAME:	Kindergarten Counting Game-494.cpp
*
*   PURPOSE:
*
*   @author:    Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    11 Oct 2016    New             1.0         Completed, Accepted
*************************************************************************/

#include<stdio.h>
#include<ctype.h>

int main() {

    char str[500];
    int i,count;
    while(scanf(" %[^\n]", str) == 1) {	//space before % is needed to skip '\n' after first line

        i=1;
        count=0;
        while(str[i]!='\0') {

            if(!isalpha(str[i]) && isalpha(str[i-1])) {
                count++;

            }

            i++;

        }

        printf("%d\n", count);

    }


    return 0;
}
