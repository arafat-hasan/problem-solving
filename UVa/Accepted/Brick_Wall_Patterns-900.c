/***********************************************************************
*   FILE NAME: 900-Brick Wall Patterns.c
*
*   PURPOSE:    Uva Problem
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    30 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/
#include<stdio.h>
#include<math.h>
#define g1 (1+sqrt(5))/2
#define g2 (1-sqrt(5))/2
#define g3 1/sqrt(5)
int main(){
	double n,f;
	while(scanf("%lf",&n)==1){
		if(n==0)
			break;
		n++;
		f=(pow(g1,n)-pow(g2,n))*g3;
		printf("%.0lf\n",f);
	}
	return 0;
}

