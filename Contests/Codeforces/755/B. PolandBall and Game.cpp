/***************************************************************
*   FILE NAME:  B. PolandBall and Game.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   15 Jan 16      New         1.0         Completed
*****************************************************************/

#include <stdio.h>
#include <string.h>

int main() {


    int i, e, p, tpol, tenm, tsaid;
    char pol[1000][501], enm[1000][501], said[2001][501];

    scanf("%i %i", &tpol, &tenm);


    for(i=0; i<tpol; i++) {
        scanf("%s", *(pol+501*i));
    }

    for(i=0; i<tenm; i++) {
        scanf("%s", *(enm+501*i));
    }


    tsaid=0;
    e=0;
    int flag=0;
    for(p=0; p<tpol; p++) {

        for(i=0; i<tsaid; i++) {
            if(strcmp(*(pol+501*p),*(said+501*i))==0) {
                flag = 1;
                break;
            }
        }

        if(p==tpol-1&&flag==1) {
            printf("NO\n");
            return 0;
        }

        if(flag==1) {
            flag=0;
            continue;
        }

        strcpy(*(pol+501*p), *(said+501*tsaid));
        tsaid++;

        for(; e<tenm; e++) {

            for(i=0; i<tsaid; i++) {
                if(strcmp(*(enm+501*e),*(said+501*i))==0) {
                    continue;
                }
            }

            if(i>=tsaid) {
                strcpy(*(pol+501*p), *(said+501*tsaid));
                tsaid++;
                break;
            }
        }

        if(e>=tenm&&i<tsaid) {
            printf("YES\n");
            return 0;
        }


    }

    return  0;
}

