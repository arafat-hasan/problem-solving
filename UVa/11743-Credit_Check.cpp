/*****************************************************************************
*   FILE NAME:	Credit Check-11743.cpp
*
*   PURPOSE:    Uva
*
*   WRITER:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    25 Oct 16      New             1.0         Accepted
*
******************************************************************************/

#include <stdio.h>

int main() {
    char str[18];
    int n, i,sum,tmp;
    scanf("%i", &n);
    while(n--) {

        scanf("%s%s%s%s", str, str+4, str+8, str+12);
        
        sum=0;
        for(i=0; i<16; i+=2) {
			
            tmp = (str[i]-48) * 2;
            
            if(tmp>9) {
                sum+=(int)(tmp/10)+(int)(tmp%10);
            }

            else {
                sum+=tmp;
            }
        }

        for(i=1; i<16; i+=2) {
            sum+=str[i]-48;
        }

        if(sum%10)
            printf("Invalid\n");
        else
            printf("Valid\n");
    }
    return 0;
}
