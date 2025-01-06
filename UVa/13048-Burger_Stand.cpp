/***********************************************************************
*   FILE NAME: Burger_Stand-13048.cpp
* 
*	LINK: https://uva.onlinejudge.org/external/130/13048.pdf
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    24 Jan 17    New             1.0         Completed,Accepted
***********************************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    int t, c = 1, i, len, count;
    char str[500];
    
    scanf("%i", &t);
    
    while(c <= t){
		
		scanf("%s", str);
		count = 0;
		len = strlen(str);
		for(i = 0; i < len; i++){
			
			if(str[i]!='D' && str[i]!='S' && str[i]!='B' && str[i+1]!='B' && str[i+2]!='B' && str[i-1]!='S' && str[i+1]!='S')
				count++;
			
		}		
		
		printf("Case %i: %i\n",c++, count);
		
	}
    
    return 0;
}
