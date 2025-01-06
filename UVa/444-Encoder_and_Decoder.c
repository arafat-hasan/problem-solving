/***********************************************************************
*   FILE NAME: Encoder and Decoder-444.c
*
*   PURPOSE:    Uva Problem
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    30 Aug 2016    New             1.0       	Completed, accepted
***********************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int i, n,j,k;
    char message[2000];

    while(gets(message)!=NULL) {

        //input section
			i = strlen(message)-1;

        if(message[0]>='0'&&message[0]<='9') {
			while(i>=0){
				n = 0;
				while(n<32){
					n = n * 10 + (message[i] - 48);
					i--;
					}
				printf("%c", n);
				}
        }
        else {

            for(;i+1; i--) {
                while(message[i]>0){
                    printf("%i", message[i] % 10);
                    message[i] /=10;
                }
           
            }
        }




        printf("\n");

    }

    return 0;
}
