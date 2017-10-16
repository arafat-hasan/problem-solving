/***************************************************************
*   FILE NAME:  Primary Arithmetic-10035.cpp
*
*   PURPOSE:
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   27 Oct 16      New         0.0         Completed, accepted
* 																								not effitient code
****************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sum_s(int a,int b,int c);
int sum_c(int a,int b,int c);

int main() {

    int xx, yy, C, len_x, len_y,ln, i, j, k, count;
    char x[50], y[50];

    while(scanf("%s %s",x,y)==2) {

        if(atoi(x)==0 && atoi(y)==0)
            break;
            
        count=0;
        C=0;
        len_x = strlen(x);
        len_y = strlen(y);
        
        len_x < len_y ? ln =  1: ln = 2;
        
        for(i = len_x-1, j= len_y-1, k=0; i >=0 || j >= 0; i--, j--, k++) {

            if(ln == 1) {
				
                if(i<0)
                    xx='0';
                else
                    xx = x[i];
                yy = y[j];
            }
            
            else {
				
                if(j<0)
                    yy='0';
                else
                    yy = y[j];
                xx = x[i];
            }

            C = sum_c(xx-48, yy-48, C);

            if(C!=0)
                count++;
        }

        if(count>1)
            printf("%i carry operations.\n", count);
        else if(count==1)
            printf("1 carry operation.\n");
        else
            printf("No carry operation.\n");
    }

    return 0;

}
//main() end


int sum_s(int a,int b,int c) {

    if(a+b+c>9)
        return (a+b+c)%10;

    return a+b+c;
}


int sum_c(int a,int b,int c) {

    if(a+b+c>9)
        return (a+b+c)/10;

    return 0;
}
