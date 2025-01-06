/**************************************************************
*   FILE NAME:  Different Digits-12527.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   25 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    int arr[5001], num_c[10], flag, temp, n, m, i,j;

    for(i=1; i<=5000; i++) {

        flag=1;
        temp=i;
        for(j=0; j<10; j++)
            num_c[j]=0;

        while(temp>0) {
            num_c[temp%10]+=1;
            temp=temp/10;
        }

        for(temp=0; temp<10; temp++) {

            if(num_c[temp]>1) {
                flag=0;
                break;
            }
        }

        if(flag==1) {
            arr[i]=1;
        }
        else
            arr[i]=0;

    }

    while(scanf("%i %i", &n, &m) == 2) {
        temp=0;
        for(i=n; i<=m; i++) {
            if(arr[i])
                temp++;
        }
        
        printf("%i\n", temp);
    }

    return 0;
}
