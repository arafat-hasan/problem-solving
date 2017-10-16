/**************************************************************
*   FILE NAME:  Tri-du-12952.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------------
*   21 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include <bits/stdc++.h> 
using namespace std;
int main() {
	int A, B;
	while (scanf("%d %d", &A, &B) == 2)
		printf("%d\n", max(A, B));
	return 0;
}
