/*
 * FILE: Scarecrow-12405.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/124/12405.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    17 FEB 2017    New             1.0		Complete,AC
 *
 */


#include <iostream>
#include <cstring>
using namespace std;

int main() {

    int T, Case = 0, scarecrow, N, i, len;
    char str[101];
    cin >> T;
    while(Case++ < T) {
        cin >> N;
        cin >> str;
        len = strlen(str);
        scarecrow = 0;
        for(i = len - 1; i >= 0; i--){
            if(str[i] == '.'){
                scarecrow++;
                i -=2;
            }
        }

        cout << "Case " << Case << ": " << scarecrow << endl;

    }

    return 0;
}
