/***********************************************************************
*   FILE NAME: Train Swapping-299.c
*
*   PURPOSE:	
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    29 Aug 2016    New             1.0         Completed,Accepted
***********************************************************************/
#include<stdio.h>
int main(){
	int train_num,i,s,t;
	scanf("%d",&t);
	while(t>0){
		s=0;
		scanf("%d",&train_num);
		int train_length[train_num];
		for(i=0;i<train_num;i++){
			scanf("%d",&train_length[i]);
		}
		for(i=0;i<train_num-1;i++){
			if(train_length[i]>train_length[i+1]){
				train_length[i]=train_length[i]+train_length[i+1];
				train_length[i+1]=train_length[i]-train_length[i+1];
				train_length[i]=train_length[i]-train_length[i+1];
				s++;
				if(i>0){
					i-=2;
				}
			}
		
		}
		printf("Optimal train swapping takes %d swaps.\n",s);
		t--;
	}
	return 0;
}
