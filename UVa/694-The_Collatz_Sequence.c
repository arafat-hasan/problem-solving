/***************************************************************************************
*   FILE NAME:  The Collatz Sequence-694.c
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

int main(){

		long long t=0,a,i,limit,a2;
		
		while(scanf("%lld %lld",&a,&limit)==2){

			if(a<0&&limit<0)
				break;

			t++; a2=a;

			for(i=0;;i++){


				if(a==1){
					i++;
					break;
				}

				else if(a>limit)
					break;

				else if(a%2)
					a=(3*a)+1;

				else
					a=a/2;


			}

			printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",t,a2,limit,i);
		}

		return 0;
	}
