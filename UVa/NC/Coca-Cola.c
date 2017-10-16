/***********************************************************************
*   FILE NAME: Coca-Cola.c
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    26 Aug 2016    New             1.0         Completed
***********************************************************************/

#include<stdio.h>
int coca(int n,int m){
	int e,k,vora;
	e=m/2;//vora botle
	k=m-e;
	vora=n+e;
	return vora+coca(0,k);
	}
	
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",coca(n,0));
	
	return 0;
	}
