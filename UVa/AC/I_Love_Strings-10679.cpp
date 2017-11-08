/**************************************************************
*   FILE NAME:  I Love Strings-10679.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   24 Oct 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    int n, i, q;
    char str[1000001], str2[1001];
    char *ret;
    scanf("%i", &n);
    
    while(n--) {

        scanf("%s", str);
        scanf("%i", &q);

        for(i=0; i<q; i++) {
			
            scanf("%s", str2);
            ret =  strstr(str, str2);
            
            if(ret != 0)
                printf("y\n");
            else
                printf("n\n");
        }
    }

    return 0;
}
