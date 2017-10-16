/***************************************************************
*   FILE NAME:  Dima and Guards.cpp
* 
*	LINK: http://codeforces.com/problemset/problem/366/A
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   13 Jan 16      New         1.0         Completed
*****************************************************************/

#include <stdio.h>
#include <limits.h>

int main() {

		int n, gp[4][3], i, a, b;
		
		scanf("%i", &n);
		for(i=0;i<4;i++){
			scanf("%i %i", &a, &b);
			if(a>b)
				gp[i][0]=b;
			else
				gp[i][0]=a;
				
			scanf("%i %i", &a, &b);
			if(a>b)
				gp[i][1]=b;
			else
				gp[i][1]=a;
			
			
			gp[i][2]=gp[i][0]+gp[i][1];
		}
		
		int min=INT_MAX, flag;
		for(i=0;i<4;i++){
			if(min>gp[i][2]){
				min=gp[i][2];
				flag=i;
			}
		}
			
		if(min>n){
			printf("-1\n");
			return 0;
			}
			
		printf("%i %i %i\n", flag+1, gp[flag][0], n-gp[flag][0]);
			
	return 0;
}
