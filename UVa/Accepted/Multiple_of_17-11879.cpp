/*******************************************************************
*   FILE NAME:  Multiple of 17-11879.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    02 Nov 2016    New             1.0         Completed,Accepted
*******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IS_Div17(char *num);
char num[101];

int main() {

    char num[101];

    while(scanf(" %s", num)==1) {

        if(num[0]=='0' && num[1]  == '\0')
            break;

        if(IS_Div17(num))
            printf("0\n");
        else
            printf("1\n");
    }


    return 0;
}


int IS_Div17(char *num) {

    long long len, cut, mns, i, ctlen;
    len = strlen(num);

    if(len <19) {
        return (atoll(num)%17);
    }

    cut = (num[len-1] - 48) * 5;
    num[len-1] = '\0';
    ctlen=5;

    for(i=0; i<14; i++) {
        if(num[len-ctlen] != '0')
            break;
        ctlen++;
    }

    mns= atoi(&num[len-ctlen])-cut;

    for(i=2; i<=ctlen; i++) {
        num[len-i]=(mns%10) +48;
        mns /=10;
    }

    return IS_Div17(num);
}
