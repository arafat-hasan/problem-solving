/***************************************************************************************
*   FILE NAME:  Big Number-1185.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   29 Sep 16      New         1.0         Completed,Accepted
**************************************************************************************/

#include <stdio.h>
#include <math.h>
double array[10000001l]={1};

int main(){

		int t,n,i;
		
		for(i=1;i<=10000000l;i++)
		   array[i]=array[i-1]+log10(i);
        
        scanf("%d",&t);
        
        while(t--)
            scanf("%d",&n),	printf("%d\n", (int) (array[n]));
            
		return 0;
	}
