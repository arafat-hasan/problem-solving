/*
 * FILE: Fill_the_Containers-11413.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/114/11413.pdf
 * LINK: http://lightoj.com/volume_showproblem.php?problem=1076&language=english&type=pdf
 *
 * Description: UVa 11413, LOJ 1076
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    07 Apr 2017    New             1.0
 *
 */


/*
    ___          ___           ___                       ___
   /  /\        /  /\         /__/\        ___          /__/\
  /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
 /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
 \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
    \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
     \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
     /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
    /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
    \__\/      \  \::/       \  \:\         \__\/      \  \:\
                \__\/         \__\/                     \__\/
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

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646

/*****************____________BIT_OPERATIONS____________****************/
// #define bit(n) (1 << (n)) //2^n
// //check ith bit of integer n, 0 or 1
// #define bitchk(n, i) ((n & (1 << i))? 1 : 0)
// #define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
// #define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
// //toggle ith bit of integer n, set 0 if 1, set 1 if 0
// #define bit_toggle(n, i) (n ^ ( 1 << i))
// //set ith bit to x (x is bool, 1 or 0) of the integer n
// #define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define ln cout << '\n';
#define sp cout << ' ';
#define lck cout << "#########\n";

typedef long long ll;
typedef double lf;
using namespace std;

bool fillthecontainer(int con){
    int 
    REP(i, n){

    }

}
int binarysearch(int *arr, int lo, int hi) {
    return 0;
}


int main() {

    std::ios::sync_with_stdio(false);
    int T, n, m, c[1000000], csum, max;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        csum = 0; max = INF;
        REP(i, n) {
            cin >> c[i];
            max = max(max, c[i]);
            csum += c[i];
        }

        binarysearch(c, max, csum);

    }

    return 0;
}


// Can the vessels fill all the m containers, each has capacity C?
bool FillAllContainers(const vector<int> &vessels, int m, int  C) {
    int container = 1;
    int capacity = C;
    for (int i = 0; i < vessels.size(); ++i) {
        // No container can contain so much milk.
        if (vessels[i] > C)
            return false;

        if (vessels[i] > capacity) {
            // Already m containers are filled.
            if (container == m)
                return false;
            ++container;
            capacity = C;
        }
        capacity -= vessels[i];
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> vessels(n);
        for (int i = 0; i < n; ++i)
            cin >> vessels[i];

        // The capacity 1<=c<=1000000000.
        int L = 1, U = 1000000000, C = 0;
        while (L <= U) {
            int mid = (L + U) / 2;
            if (FillAllContainers(vessels, m, mid)) {
                C = mid;
                U = mid - 1;
            } else
                L = mid + 1;
        }
        cout << C << endl;
    }
    return 0;
}

