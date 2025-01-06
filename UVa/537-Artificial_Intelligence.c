/***********************************************************************
*   FILE NAME: Artificial_Intelligence-537.c
*
*   PURPOSE: Solve of Uva problem p537.
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         Completed, accepted
***********************************************************************/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main() {
    int t=0,i,j,vf,Pf,end;
    float v,P,I,mul=1;
    char ch,str[10000];
    scanf("%d ",&i);

    while(t<i) {
        end=0;
        vf=0;
        Pf=0;
        while(scanf("%c",&ch)) {

            if(ch=='=') {
                end++;
                for(j=0;; j++) {
                    scanf("%c",&str[j]);
                    if(str[j]=='W'||str[j]=='V'||str[j]=='A')
                        break;
                }
                ch=str[j];
                if(isalpha(str[j-1])) {
                    if(str[j-1]=='m')
                        mul=1e-3;
                    else if(str[j-1]=='k')
                        mul=1e3;
                    else
                        mul=1e6;
                    str[j-1]=0;
                }
                else
                    str[j]=0;
                if(ch=='W') {
                    P=atof(str)*mul;
                    Pf=1;
                    mul=1;
                } else if(ch=='V') {
                    v=atof(str)*mul;
                    vf=1;
                    mul=1;
                } else {
                    I=atof(str)*mul;
                    mul=1;
                }
            }
            if(end==2) break;
        }



        if(Pf==0) {
            printf("Problem #%d\nP=%.2fW\n\n",t+1,v*I);
        } else if(vf==0) {
            printf("Problem #%d\nU=%.2fV\n\n",t+1,P/I);
        } else
            printf("Problem #%d\nI=%.2fA\n\n",t+1,P/v);
        t++;
    }
    return 0;
}
