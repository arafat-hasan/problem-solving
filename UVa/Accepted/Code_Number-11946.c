/**************************************************************
*   FILE NAME:  Code Number-11946.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------
*   24 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,n;
    char line[1000];

    scanf("%d",&n);
    getchar();
    for(i=1; i<=n; i++) {

        while(gets(line)) {

            if(strlen(line)==0) {
                break;
            }

            for(j=0; line[j]!='\0'; j++) {

                switch(line[j]) {
                case '3': {
                    line[j]= 'E';
                    break;
                }
                case '1': {

                    line[j]='I';
                    break;
                }
                case '4': {

                    line[j]='A';
                    break;
                }
                case '9': {

                    line[j]='P';
                    break;
                }
                case '8': {

                    line[j]='B';
                    break;
                }
                case '5': {

                    line[j]='S';
                    break;
                }
                case '7': {

                    line[j]='T';
                    break;
                }
                case '2': {

                    line[j]='Z';
                    break;
                }
                case '6': {

                    line[j]='G';
                    break;
                }
                case '0': {

                    line[j]='O';
                    break;
                }
                }
                printf("%c",line[j]);
            }
            printf("\n");
        }
        if(i!=n)
        {
            printf("\n");
        }
    }
    return 0;
}
