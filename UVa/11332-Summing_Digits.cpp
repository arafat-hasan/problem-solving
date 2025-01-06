/**************************************************************
*   FILE NAME:  Summing Digits-11332.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   27 Oct 16      New         1.0         Completed, Accepted
***************************************************************/

#include <stdio.h>
int f(int num) {

    if(num<10)
        return num;

    int temp;
    temp = num;
    num = 0;

    while(temp>0) {
        num += temp % 10;
        temp = temp / 10;
    }

    return f(num);

}

int main() {

    int num;
    while(scanf("%i", &num)==1) {

        if(num == 0)
            break;
        printf("%i\n", f(num));

    }

    return  0;
}
