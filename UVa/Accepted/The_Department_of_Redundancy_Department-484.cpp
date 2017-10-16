/*
 * FILE: The_Department_of_Redundancy_Department-484.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat<at>gmail<dot>com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    02 Mar 2017    New             1.0        AC
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <list>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back


#define nl cout << endl;
#define lck cout << "______________" << endl;

typedef long long ll;

int main() {
    int n;
    std::map<int, int> mymap;
    std::list<int>::iterator j;
    std::list<int> order;
    while(scanf("%d", &n) == 1){
        if(mymap.count(n) == 0){
            mymap[n] = 1;
            order.push_back(n);
        }
        else mymap[n]++;
    }
    for(j = order.begin(); j != order.end(); j++){
        printf("%d %d\n", *j, mymap[*j]);
    }
    return 0;
}

