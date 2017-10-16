/***********************************************************************
*   FILE NAME: F-Marvelous_Mazes_2.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    24 Jan 17    New             1.0         Completed,NC
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char str[1000];
    int len, i, k, j, sum;

    while(gets(str)) {
        printf("%s", str);
        scanf("%*c");
        if(str[0]=='\n')
            printf("\n");

        else {

            len = strlen(str);


            for(i=0; i< len; ) {
                if(str[i]=='!')
                    printf("\n");

                else if((isdigit(str[i])) && (isalpha(str[i+1]))) {
                    for(j=0; j<str[i]-48; j++)
                        printf("%c", str[i+1]);

                    i+=2;


                }

                else if(isdigit(str[i]) && isdigit(str[i+1])) {
					printf("$$$$$\n");
                    sum=0;
                    for(j=i; str[j] >= '0' && str[j] <= '9'; j++) {
                        sum+=str[j]-48;


                    }
                    printf("%i %c %i\n",j, str[j], sum);
                    for(k=0; k<sum; k++)
                        printf("*%c", str[k+1]);

                    i = j+2;
                }
            }
        }
    }

    return 0;
}
