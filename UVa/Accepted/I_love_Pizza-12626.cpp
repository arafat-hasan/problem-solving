/******************************************************************************
*   FILE NAME:  I ❤ Pizza-12626.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   17 Nov 16		New			1.0			Accepted
*******************************************************************************/

#include <stdio.h>
#include <limits.h>

int main() {

    int M, A, R, G, I, T, t, i;
    char str[601];
    scanf("%i", &t);
    while(t--) {
        M=A=R=G=I=T=0;
        scanf("%s", str);
        i=0;
        while(str[i] != '\0') {

            switch(str[i]) {

            case 'M':
                M++;
                break;

            case 'A':
                A++;
                break;

            case 'R':
                R++;
                break;

            case 'G':
                G++;
                break;

            case 'I':
                I++;
                break;

            case 'T':
                T++;
                break;

            default:
                break;

            }
            i++;
        }

        A /=3;
        R /=2;
        
        i = M;
        if(i > A)
            i = A;
        if(i > R)
            i = R;
        if(i > G)
            i = G;
        if(i > I)
            i = I;
        if(i > T)
            i = T;
            
        printf("%i\n", i);

    }

    return 0;
}
