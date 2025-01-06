/***********************************************************************
*   FILE NAME: Soda Surpler-11689.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    30 Aug 2016    New             1.0         Completed
***********************************************************************/

#include<stdio.h>

int cola(int n,int c){
	if(n<c)
		return 0;
	int y;
	static int o;
	y=n/c;
	o=n%c;
	return y+cola(y+o,c); 
	}

int main(){
	int t,e,f,c;
	scanf("%d",&t);
	while(scanf("%d %d %d",&e,&f,&c)==3&&t){
			printf("%d\n",cola(e+f,c));
			t--;
	}
		
	return 0;
	}
