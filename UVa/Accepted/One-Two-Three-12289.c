/*****************************************************************************
*   FILE NAME:	One-Two-Three-12289.c
*
*   PURPOSE:    Uva
*
*   @author: Md. Arafat Hasan Jenin, 1st year 1st semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    04 Sep 16      New             1.0         Newly written, Accepted
*
******************************************************************************/
#include<stdio.h>
int main(){
	int t,i,n,e,w,o,c;
	char s[6];
	scanf("%d",&c);
	while(c){printf("##%d\n",t);
		n=0;e=0;t=0;w=0;o=0;
		scanf("%s",s);
		for(i=0;;i++){
			if(s[i]==0)
				break;
			if(s[i]=='n')
			n++;
			if(s[i]=='e')
			e++;
			if(s[i]=='t')
			t++;
			if(s[i]=='w')
			w++;
			if(s[i]=='o')
			o++;
		}
		if(i==5){
			printf("3\n");
		}
		else if((o&&n)||(n&&e)||(e&&o)){
			printf("1\n");
		}
		

		else if((t&&w)||(w&&o)||(o&&t)){
			printf("2\n");
		}

	
		c--;
	}

	return 0;
}
