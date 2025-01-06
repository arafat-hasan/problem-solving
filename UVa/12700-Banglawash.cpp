/***********************************************************************
*   FILE NAME: Banglawash-12700.cpp
*
*   PURPOSE: 
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    10 Jul 2016    New             1.0         Completed, accepted
***********************************************************************/
#include <stdio.h>

int main() {

    int t, i,m,j=0;
    int  _b,_w,_t,_a;
    char N[12];
    scanf("%i", &t);
    while(j<t) {

        scanf("%i", &m);
                    _b=_w=_t=_a=0;
        for(i=0; i<m; i++) {

            scanf(" %c", &N[i]);

            switch(N[i]) {

            case 'B':
                _b++;
                break;

            case 'W':
                _w++;
                break;

            case 'T':
                _t++;
                break;

            case 'A':
                _a++;
                break;

            default :
                break;

            }


        }
j++;
        if(_w==0 && _t==0 && _a!=m)
            printf("Case %i: BANGLAWASH\n", j);

        else if(_b==0 && _t==0 && _a!=m)
            printf("Case %i: WHITEWASH\n", j);

        else  if(_a == m)
            printf("Case %i: ABANDONED\n", j);

        else  if(_w == _b )
            printf("Case %i: DRAW %i %i\n", j, _b, _t);

        else  if(_b>_w)
            printf("Case %i: BANGLADESH %i - %i\n", j, _b, _w);

        else  if(_w>_b)
            printf("Case %i: WWW %i - %i\n", j, _w, _b);


    }


    return 0;
}
