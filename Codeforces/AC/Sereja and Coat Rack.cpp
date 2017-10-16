/***************************************************************
*   FILE NAME:	Sereja and Coat Rack.cpp
* 
*	LINK: http://codeforces.com/problemset/problem/368/A
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
#include<algorithm>
using namespace std;

int main() {

	int n, d, i, sum=0,m;
	scanf("%i %i", &n, &d);
	int a[n];
	
	for(i=0;i<n;i++){
		scanf("%i", &a[i]);
		sum+=a[i];
	}
	
	scanf("%i", &m);
	
	sort(a, a+n);
	
	if(m>=n)
		printf("%i\n", sum-(d*(m-n)));
	else{
		sum=0;
		for(i=0;i<m;i++){
			sum+=a[i];
		}
		printf("%i\n", sum);
		
	}
	
	return 0;
}
