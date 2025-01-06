/***************************************************************
*   FILE NAME:  B. PolandBall and Game-2.cpp
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

template<typename T>inline T GCD(T a, T b)
{
    if (b == 0)return a;
    else return GCD(b, a % b);
}

template<typename T>inline T LCM(T a, T b)
{
    LL res=a*b;
    res/=GCD(a,b);
    return res;
}

template<typename T>inline ULL BIGMOD(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return SQ(BIGMOD(a, b / 2, m)) % m;
    else return (a % m*BIGMOD(a, b - 1, m)) % m;
}

template<typename T>inline T POWER(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}


int main() {


    int i, tpol, tenm, j;
    char pol[1001][1000], enm[1001][1000];

    scanf("%i %i", &tpol, &tenm);

    for(i=0; i<tpol; i++) {
        scanf("%s", *(pol+1000*i));
    }

    for(i=0; i<tenm; i++) {
        scanf("%s", *(enm+1000*i));
    }

    int match=0;
    for(i=0; i<tpol; i++) {
        for(j=0; j<tenm; j++) {
            if(strcmp(*(pol+1000*i),*(enm+1000*j))==0) {
                match++;
            }
        }
    }
    
    if((tpol-match)<(tenm-match)) {
        printf("NO\n");
    }

    else {
        printf("YES\n");
    }
    
    return  0;
}

