/***********************************************************************
*   FILE NAME: Jolly Jumpers-10038.c
*
*   PURPOSE:Uva
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    31 Aug 2016    New             1.0         Completed,Accepted
***********************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(){
int t,i,d,swap,flag;
	while(scanf("%d",&t)==1){
		int jolly[t],diff[t-1];
		flag=1;
		for(i=0;i<t;i++){
			scanf("%d",&jolly[i]);
		}
		if(t>2){
			for(i=0;i<t-1;i++){
				diff[i]=abs(jolly[i]-jolly[i+1]);
			}
		

			//Bubble sort strt
			for (i = 0 ; i < t-2 ; i++){
				for (d = 0 ; d < t - i - 2; d++){
					if (diff[d] > diff[d+1]){ /* For decreasing order use < */
						swap       = diff[d];
						diff[d]   = diff[d+1];
						diff[d+1] = swap;
					}
				}
			}
			//Bubble sort
			if(diff[t-1]>=t||diff[0]!=1){
				flag=0;
			}
			if(flag==1)
			for(i=0;i<t-2;i++){
				if(diff[i]+1!=diff[i+1]){
				flag=0;
				break;
				}
			}
		}
		if(flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
		}
	return 0;
}
