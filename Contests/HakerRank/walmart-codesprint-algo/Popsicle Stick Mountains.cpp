/**************************************************************
*   FILE NAME:  Popsicle Stick Mountains.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------------
*   29 Oct 16      New         1.0         Completed,Not-Accepted
* 																								RE
****************************************************************/
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int t,j,tmp;
    scanf("%i", &t);
    int n[t], i=0, max = INT_MIN;

    while(i<t) {
        scanf("%i", &n[i]);
        if(n[i]>max) {
            max=n[i];
        }
        i++;
    }

    int row = (int) pow(2,max);
    char str[row][max];

    for(j=0; j<row; j++) {
        for(i=0; i<max; i++) {
            str[j][i] = 0;
        }
    }


    for(j=0; j<row ; j++) {

        tmp = j;
        i=0;

        while(tmp>0) {
            str[j][i] = tmp % 2;
            tmp /= 2;
            i++;
        }
    }

    for(j=0; j<row; j++) {
        for(i=0; i<max; i++) {
            if(str[j][i]==0)
                str[j][i]=-1;
        }
    }





    int count, flag, sum,k,dg;
    int ans[max];


    for(i=2; i<=max; i+=2) {
        dg=(int)pow(2,i);


        count=0;

        for(j=0; j< dg; j++) {
            flag=1;
            sum=0;
            for(k=0; k<i; k++) {
                sum +=str[j][k];

                if(sum<0) {
                    flag=0;
                    break;
                }
            }

            if(sum!=0) {
                flag=0;
            }

            if(flag) {
                count++;
            }

        }
        ans[i]=count;


    }


    for(j=0; j<t; j++) {
        sum=0;
        for(i=2; i<=n[j]; i+=2) {
            sum+=ans[i];
        }
        printf("%i\n", sum);
    }


    return 0;
}
