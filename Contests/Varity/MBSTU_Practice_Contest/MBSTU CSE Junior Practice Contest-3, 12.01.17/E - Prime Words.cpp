/***************************************************************
*   FILE NAME:  E - Prime Words.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   12 Jan 16      New         1.0         Completed, AC
*****************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
int IsPrime(int num);
int main() {
    char str[21];
    int sum, len, i;
    while(scanf("%s", str) == 1) {

        len = strlen(str);
        sum = 0;
        for(i = 0; i < len; i++) {

            if(str[i]>='A' && str[i]<='Z') {
                sum += str[i] - 38;
            }

            else
                sum += str[i] - 96;
        }

        if(IsPrime(sum)==1)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");

    }
    return 0;
}

int IsPrime(int num) {

    int i,root=sqrt(num);
    if(num<2)
        return 1;
    if(num==2)
        return 1;
    if(num%2==0)
        return 0;
    for(i=3; i<=root; i+=2)
        if(num%i==0)
            return 0;
    return 1;
}
