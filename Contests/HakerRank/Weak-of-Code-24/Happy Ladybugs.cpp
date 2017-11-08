/***************************************************************************************
*   FILE NAME:	Happy Ladybugs.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   14 Oct 16      New         1.0         Completed,Accepted
**************************************************************************************/
#include <stdio.h>
int  frcq[26];
int main() {

    int g, n, i, c, fl;
    char str[101];

    scanf("%i", &g);

    while(g--) {

        scanf("%i", &n);
        scanf("%s",str);
        if(g==0&&n==1&&str[0]!='_') {
            printf("YES\n");
            return 0;
        }
        c=0;
        for(i=0; i<=25; i++)
            frcq[i]=0;

        for(i=0; i<n; i++) {

            if(str[i]!= '_') {
                frcq[str[i]-65]++;
            }

            else
                c++;

        }

        if(c) {
            if(c==1&&n==1)
                printf("YES\n");

            else
            {
                fl=1;
                for(i=0; i<=25; i++) {

                    if(frcq[i] == 1) {
                        fl=0;
                        break;
                    }

                }

                if(fl) {
                    printf("YES\n");
                }
                else {
                    printf("NO\n");
                }

            }

        }



        else {

            fl=1;
            for(i=0 ; i<n; i++) {
                if(i==0) {
                    if(str[i] != str[i+1]) {
                        fl=0;
                        break;
                    }
                }
                else if(i==n-1) {
                    if(str[i]!=str[i-1]) {
                        fl=0;
                    }
                }

                else {

                    if(str[i]!=str[i+1] && str[i] != str[i-1]) {

                        fl=0;
                        break;
                    }
                }
            }

            if(fl)
                printf("YES\n");
            else
                printf("NO\n");

        }

    }

    return 0;
}
