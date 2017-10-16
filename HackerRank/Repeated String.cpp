/***************************************************************
*   FILE NAME:  Repeated String.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   16 Oct 16      New         1.0         In completed
******************************************************************/
#include <stdio.h>
#include <string.h>
int main() {

    int len, extra, count;
    long long n, ans, i;
    char a[101];

    scanf("%s", a);
    scanf("%lli", &n);

    len = strlen(a);

    for(i = 0; i < len; i++) {
        if(a[i] == 'a')
            count++;
    }


    ans = n / len;
    extra = n - (ans * len);
    ans *= count;

    for(i = 0; i < extra; i++) {
        if(a[i] == 'a')
            ans++;
    }

    printf("%lli\n", ans);

    return 0;

}
