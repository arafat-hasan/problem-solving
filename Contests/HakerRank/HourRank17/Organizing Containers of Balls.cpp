/*
 * FILE: Organizing Containers of Balls.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 *
 */


#include <iostream>
using namespace std;

int main() {

    int q, n, i, sum, j;
    
    cin >> q;
    while(q--){
		cin >> n;
		int M[n][n];
		for(i=0; i < n; i++){
			for( j = 0; j < n; j++)
			cin >> M[i][j];
		}
		
		for(i = 0; i < n; i++){
			sum = 0;
			for(j = 0; j < n; j++){
				sum += M[j][i];
			}
			
			if(sum != n){
				cout << "Impossible" << endl;
				return 0;
			}
		}
		
		if(i == n)
		cout << "Possible" << endl;
		
	}
    return 0;
}

