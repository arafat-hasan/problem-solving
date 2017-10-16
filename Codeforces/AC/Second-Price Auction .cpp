/*****************************************************************************
*   FILE NAME:	Second-Price Auction .cpp
* 	LINK: http://codeforces.com/problemset/problem/386/A
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin, 1st year 2nd semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    15 Jan 16      New             1.0         Newly written, Accepted
*
******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
    
    int n, b[1001], i;
    int max=INT_MIN, index;
    scanf("%i", &n);
    
    for(i=0;i<n;i++){
		scanf("%i", &b[i]);
		if(b[i]>max){
			max=b[i];
			index=i;
			}
	}
	
	sort(b, b+n);
	printf("%i %i", index+1, b[n-2]);
	
    return 0;
}
