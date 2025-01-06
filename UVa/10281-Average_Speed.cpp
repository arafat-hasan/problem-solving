/*
 * FILE: Average_Speed-10281.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    20 Feb 2017    New             1.0        AC
 *
 */


#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
  
    double speed = 0, dis, dis_str;
    int h, m, s, hb, mb, sb, t;
    char ch;
    while(cin >> h){
        cin >> ch >> m >> ch >> s;
        scanf("%c", &ch);
        t = ((h - hb) * 60 + (-mb + m))*60 + -sb + s;
        if(ch == ' '){  
            dis_str += (speed/3.6F) * t;
            cin >> speed;
            hb = h, mb = m, sb = s;
            continue;
        }
        dis = (speed/3.6F) * t + dis_str;
        cout.fill('0');
        cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) <<s << " ";
        cout << fixed << setprecision(2);
        cout  << dis/1000 << " km" << endl;        
    }

    return 0;
}
