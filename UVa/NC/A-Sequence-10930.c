/***********************************************************************
*   FILE NAME: A-Sequence-10930.c
*
*   PURPOSE:	
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    27 Aug 2016    New             1.0         In-completed,Not submited
***********************************************************************/

#include<stdio.h>
int main(){
	int seq[1010],i,j,t=0,n,sum,k,l, E;

	while(scanf("%d",&n)!=EOF){
		i=0;E=1;t++;
		printf("Case #%d:",t);
		while(n&&scanf("%d",&seq[i])==1){
			n--;
			printf(" %d",seq[i]);
			if(seq[i]<1){
				E=0;
				}
			if(seq[i]<seq[i-1]&&i>0){
				E=0;
			}
			if(E==1)
				for(k=2;k<=i;k++){
					for(j=0;j<=i-k;j++){
						sum=0;
						for(l=0;l<k;l++){
							sum+=seq[j+l];
						}
						if(sum==seq[i]){
								E=0;
								break;
							}
					}
				}
			i++;
		}
			if(E==1)
				printf("\nThis is an A-sequence.\n");
			else
				printf("\nThis is not an A-sequence.\n");
	}
	return 0;
	}
