/***********************************************************************
*   FILE NAME:  Find the Telephone-10921.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    05 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include<stdio.h>
int main() {
    int i;
    char c[40];
    while(scanf("%s",&c)!=EOF) {
        for(i=0; c[i]!=0; i++) {
            if(c[i]>='A'&&c[i]<='C')
                c[i]='2';
            else if(c[i]>='D'&&c[i]<='F')
                c[i]='3';
            else if(c[i]>='G'&&c[i]<='I')
                c[i]='4';
            else if(c[i]>='J'&&c[i]<='L')
                c[i]='5';
            else if(c[i]>='M'&&c[i]<='O')
                c[i]='6';
            else if(c[i]>='P'&&c[i]<='S')
                c[i]='7';
            else if(c[i]>='T'&&c[i]<='V')
                c[i]='8';
            else  if(c[i]>='W'&&c[i]<='Z')
                c[i]='9';
        }
        printf("%s\n",c);
    }
    return 0;
}
