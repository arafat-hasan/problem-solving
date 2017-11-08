/*
 * FILE: All_in_All-10340.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/103/10340.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    18 FEB 2017    New             1.0		Completed, AC
 *
 */


#include <iostream>
#include <cstring>
using namespace std;

int main() {

    int i, j, len1, len2;
    char str1[1000000], str2[1000000]; 
    while(cin >> str1 >> str2){
        len1 = strlen(str1); len2 = strlen(str2);
        j = 0;
        for(i = 0; i < len2; i++){
            if(str2[i] == str1[j]){
                j++;  
                if(j == len1) break;
            }
        }
        j == len1? cout << "Yes" << endl: cout << "No" << endl;
    }
    return 0;
}
