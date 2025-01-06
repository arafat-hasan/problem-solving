/***************************************************************
*   FILE NAME:  Sum of Consecutive Prime Numbers-1210.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   02 Nov 16      New         1.0         Completed, Accepted
*****************************************************************/
#include <stdio.h>
int ans[10005] = {};
int main() {

    int arr[10005], i, j, k, prime[1300],n;

    for(i=0; i<10005; i++) {
        arr[i]=i;
    }

    k=0;
    for(i=2; i<10005; i++) {
        if(arr[i]) {
            prime[k]=arr[i];
            k++;
            for(j = i * 2; j<10005; j+=i)
                arr[j]=0;
        }
    }


    for(i = 0; i < k; i++) {
        int tmp = 0;
        for(j = i; j < k; j++) {
            tmp += prime[j];
            if(tmp > 10000) break;
            ans[tmp]++;
        }
    }

    while(scanf("%i", &n) ==1 && n) {
        printf("%i\n", ans[n]);
    }

    return 0;
}
