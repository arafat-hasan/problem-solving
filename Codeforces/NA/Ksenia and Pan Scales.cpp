/*****************************************************************************
*   FILE NAME:	Ksenia and Pan Scales.cpp
* 	LINK: http://codeforces.com/problemset/problem/382/A
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin, 1st year 2nd semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    15 Jan 16      New             1.0         Newly written, Accepted
*
******************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char str[500000], un_used[500000];

    scanf("%s", str);
    scanf("%s", un_used);

    int len_un_used = 	strlen(un_used);
    int len_str = 	strlen(str);
    int r = 0, l =0;
    for(i=0; i<len_str; i++) {
        if(str[i]=='|')
            break;
        l++;
    }

    for(i++; i<len_str; i++) {
        r++;
    }

    if((len_un_used+l==r)) {

        for(i=0; i<l; i++)
            printf("%c", str[i]);
        printf("%s" ,un_used);
        for(; i<len_str; i++)
            printf("%c", str[i]);
        printf("\n");
    }

    else if(len_un_used+r==l) {
        printf("%s", str);
        printf("%s\n",un_used);

    }


    else if((r==l)&&len_un_used%2==0) {
        int half=len_un_used/2;


        for(i=0; i<l; i++)
            printf("%c", str[i]);

        int m=i;

        for(i=0; i<half; i++) {
            printf("%c", un_used[i]);

        }

        i=m;
        for(; i<len_str; i++)
            printf("%c", str[i]);

        i=half;

        for(; i<len_un_used; i++) {
            printf("%c", un_used[i]);
        }
        printf("\n");

    }

    else {
        printf("Impossible\n");
    }


    return 0;
}
