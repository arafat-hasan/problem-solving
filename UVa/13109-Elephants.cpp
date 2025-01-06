/***********************************************************************
*   FILE NAME: Elephants-13109.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    29 Aug 2016    New             1.0         Completed, Accepted
***********************************************************************/

#include <iostream>
#include <algorithm>
#include <set>

#define MAX 100005

using namespace std;


//0.260s
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Elephant_num, i, t, max_load;
    int Elephant_waight;
    long long s;
    multiset<int> ms;
    multiset<int>::iterator it;
    cin >> t;
    while (t--) {
        cin >> Elephant_num >> max_load;

        for (i = 0; i < Elephant_num; i++) {
            cin >> Elephant_waight;
            ms.insert(Elephant_waight);
        }
        s = 0;
        for (it = ms.begin(), i = 0; it != ms.end(); it++, i++) {
            s += *it;
            if (s > max_load)
                break;
        }
        cout << i << '\n';
        ms.clear();
    }
    return 0;
}


//29 Aug 2016
//Accepted, 0.090s
//int main() {
//    long long Elephant_num,i,s,t,max_load;
//    scanf("%lld",&t);

//    while(t>0) {
//        s=0;
//        scanf("%lld %lld",&Elephant_num,&max_load);

//        long long Elephant_waight[Elephant_num];
//        for(i=0; i<Elephant_num; i++) {
//            scanf("%lld",&Elephant_waight[i]);
//        }

//        sort(Elephant_waight, Elephant_waight + Elephant_num);

//        for(i=0; i<Elephant_num; i++) {
//            s+=Elephant_waight[i];
//            if(s>max_load)
//                break;
//        }

//        printf("%lld\n",i);
//        t--;
//    }
//    return 0;
//}
