/**************************************************************
*   FILE NAME:  Cacho-13130.cpp
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
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		int ret = 1, x, p;
		for (int i = 0; i < 5; i++) {
			scanf("%d", &x);
			if (i)
				ret &= x == p+1;
			p = x;
		}
		puts(ret ? "Y" : "N");
	}
	return 0;
}
