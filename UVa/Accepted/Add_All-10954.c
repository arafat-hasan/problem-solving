/*****************************************************************************
*   FILE NAME:	Add_All-10954.c
*
*   PURPOSE:    Uva
*
*   WRITER: Md. Arafat Hasan Jenin, 1st year 1st semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    02 Sep 16      New             1.1         Newly written, Accepted
*
******************************************************************************/

#include<stdio.h>
void bubble(int n, int *array){
	int c,d,swap;
	for (c = 0 ; c < ( n - 1 ); c++){
		for (d = 0 ; d < n - c - 1; d++){
			if (array[d] > array[d+1]){ /* For decreasing order use < */
				swap = array[d];
				array[d] = array[d+1];
				array[d+1] = swap;
			}
		}
	}
}

	
int binsrch(int search,int n, int *array){
	int first, last, middle;
	if(search<array[0]){
		return -1;
	}
	if(search>array[n-1]){
		return n-1;
	}
	first = 0;
   last = n - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
		if (array[middle] < search)
			first = middle + 1;    
		else if (array[middle] == search) {
			return middle;
			break;
		}
		else
			last = middle - 1;
 
		middle = (first + last)/2;
	}
	if (first > last)
		return last;
	return 0;
}

		 
int insert (int n,int *array, int ins,int ent){
	int i;
	if(ins==-1){
		array[-1]=ent;
		return 0;	 
	}
	for(i=0;i<=ins;i++){
		array[i-1]=array[i];
	}
	array[ins]=ent;
	return 0;
}
	
int main() {
    int temp,t,i,b,ans;
	while(scanf("%d",&t)==1&&t){
		i=0;ans=0;
		int a[t];
		while(i<t&&scanf("%d",&a[i])==1) {
		    	i++;
		}
		

		bubble(t,a);
		for(i=0;i<t-1;i++){
			temp=a[i]+a[i+1];
			ans+=temp;
			b=binsrch(temp,t-i-2,a+i+2);
			insert(t-i-2,a+i+2,b,temp);
		}
		printf("%d\n",ans);	
    }
    return 0;
}
