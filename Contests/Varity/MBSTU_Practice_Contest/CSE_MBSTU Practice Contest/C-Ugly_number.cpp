/*
 * FILE: C-Ugly_number.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 *
 */


#include <iostream>
#include <vector>
using namespace std;
void fun(int n);

int vis[1501], ar[3] = {2, 3, 5};
vector<int>ugly;

int main() {

    fun(1);
    cout << ugly[1500] << endl;
    return 0;
}

void fun(int n) {
	
	int i;
	if(vis[n] == 1 || n > 1501) return ;	
	vis[n] == 1;
	ugly.push_back(n);
	for(i = 0; i < 3; i++)
		fun(n * ar[i]);
	
	
}

