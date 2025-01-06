/*
 * FILE: A._Dasha_and_Stairs.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: http://codeforces.com/contest/761/problem/0
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    31 Jan 2017    New             1.0
 *
 *
 */


#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int e, o;
    cin >> e >> o;
    if((abs(e-o)<=1) && (e||o)){
		cout << "YES" <<endl;
		
	}
    else cout << "NO" << endl;
    return 0;
}
