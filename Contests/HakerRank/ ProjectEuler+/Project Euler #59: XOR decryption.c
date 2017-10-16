/***********************************************************************
*   FILE NAME: Project Euler #59: XOR decryption.c
*
*   PURPOSE: 
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    18 Aug 2016    New             1.0         Completed, accepted
***********************************************************************/

#include<stdio.h>
int ck(int x){
	return ((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>='0'&&x<='9')||x==';'||x==':'||x==','||x=='.'||x=='\''||x=='?'||x=='-'||x=='!'||x==' '||x=='('||x==')');
	}
	
int main(){
	int n,j,i;
	char a,b,c;
	scanf("%d",&n);
	int m[n];
	for(i=0;i<n;i++)
		scanf("%d",&m[i]);


	for(i=97;i<=122;i++){
		for(j=0;j<n;j+=3)
			if(ck(m[j]^i)!=1)
				break;
		if(j>=n)
		break;
	}
	a=i;
	
	for(i=97;i<=122;i++){
		for(j=1;j<n;j+=3)
			if(ck(m[j]^i)!=1)
				break;
		if(j>=n)
		break;
	}
	b=i;
	
		for(i=97;i<=122;i++){
		for(j=2;j<n;j+=3)
			if(ck(m[j]^i)!=1)
				break;
		if(j>=n)
		break;
	}
	c=i;
	
	printf("%c%c%c",a,b,c);
	return 0;
}
