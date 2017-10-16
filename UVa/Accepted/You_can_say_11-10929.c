/***************************************************************************************
*   FILE NAME:  You can say 11-10929.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   03 Oct 16      New         1.0         Completed,Accepted
**************************************************************************************/

#include <stdio.h>

int main(){

		int i,sum;
		char c[10000];

		while(1){

			sum=0;

				for(i=0;;i++){

					scanf("%c",&c[i]);


					if(c[i] == '\n'){
						c[i]='\0';
						break;
					}

					
					if(i%2)
						sum-=c[i]-48;
					else
						sum+=c[i]-48;

				}


				if(c[0] == '0' && c[1] == '\0')
					break;


					if(sum % 11)
						printf("%s is not a multiple of 11.\n",c);

					else
						printf("%s is a multiple of 11.\n",c);

		}

	
		return 0;

	}



