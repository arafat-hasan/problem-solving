/***********************************************************************
*   FILE NAME: B - Domino .cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    11 Jun 2017    New             1.0         in-Completed,Not-Accepted
***********************************************************************/

#include <stdio.h>
int fact(int n);
int main() {

	int n, x[100], y[100], up=0, dw=0, i;
	scanf("%i", &n);
	
	for(i=0;i<n;i++){
		scanf("%i %i", &x[i], &y[i]);
		}
	
	 int j=0;
x:
	for(i=0;i<n;i++){
		up+=x[i];
		}
			
	for(i=0;i<n;i++){
		dw+=y[i];
		}
		
	if((up%2!=0)||(dw%2!=0)){
		x[j]=y[j]+x[i];
		y[j]=x[j]-y[j];
		x[j]=x[j]-y[i];
		
		if(j>=fact(n) || n==1){
			printf("-1\n");
			return 0;
		}
		j++;
		goto x;
		
	}
	else
	printf("%i\n", j);
		
		
		
    return 0;
}

int fact(int n){
	
	if(n==0||n==1)
		return 1;
		
	return n*fact(n-1);
	
	}

