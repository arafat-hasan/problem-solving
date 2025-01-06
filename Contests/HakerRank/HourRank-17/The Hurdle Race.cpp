/*
 * FILE: The Hurdle Race.cpp
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
 *    ** *** 2017    New             1.0		AC
 *
 *
 */


#include <iostream>
using namespace std;

int main() {

    int n, h, i, tmp, count=0;
    cin >> n >> h;

    for(i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp > h){
            count += tmp - h;
            h = tmp;
        }
    }

    cout << count << endl;

    return 0;
}

