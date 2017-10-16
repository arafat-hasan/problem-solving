/*****************************************************************************
*   FILE NAME:	C - Mother bear.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin, 1st year 2nd semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    15 Jan 16      New             1.0         Newly written, Accepted
*
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    int i, j, len;
    char str1[100000], str[100000];

    while(scanf(" %[^\n]", str1)==1) {
		

		if(str1[0]=='D'&&str1[1]=='O'&&str1[2]=='N'&&str1[3]=='E')
			break;

        len = strlen(str1);

        for(i=0, j=0; i<len; i++) {
            if((str1[i]>='a'&&str1[i]<='z')||(str1[i]>='A'&&str1[i]<='Z')) {
                str[j++]=tolower(str1[i]);
            }
        }
        
        j--;

        for(i=0; i<j; i++, j--) {
            if(str[i]!=str[j]) {
                break;
            }
        }
        
        if(i<j)
            printf("Uh oh..\n");
        else
            printf("You won't be eaten!\n");

    }

    return 0;
}


/*
*
Madam, Im adam!
Roma tibi subito motibus ibit amor.
Me so hungry!
Si nummi immunis
DONE
*/
