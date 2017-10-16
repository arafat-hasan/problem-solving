/**************************************************************
*   FILE NAME:  Three Families-12502.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------
*   21 Nov 16      New         1.0         NC
***************************************************************/

#include<stdio.h>

int main() {
    int a, b, c, n, e;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &c);
        e = c * (a + (a - b)) / (a + b);
        if (e <= 0)
            printf("0\n");
        else
            printf("%d\n", e);
    }
    return 0;
}
