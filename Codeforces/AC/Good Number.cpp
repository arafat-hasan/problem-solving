/***************************************************************
*   FILE NAME:	Good Number.cpp
* 
*	LINK: http://codeforces.com/problemset/problem/365/A 
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   13 Jan 16      New         1.0         not-Completed
*****************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
	
	char str[20];
	int i, count, n, k, len, flag;
	int chk[10];
	scanf("%i %i", &n, &k);
	count=0;
	
	while(n--){
		scanf("%s", str);
		
		for(i=0;i<=k;i++)
			chk[i]=0;
		
		len=strlen(str);
		for(i=0;i<len;i++){
			chk[str[i]-48]++;
		}
		
		flag=1;
		for(i=0; i<=k;i++){
			if(chk[i]<1){
				flag=0;
				break;
			}	
		}
		
		if(flag)
			count++;
	}
	
	
	printf("%i\n", count);
	
	return 0;
}
