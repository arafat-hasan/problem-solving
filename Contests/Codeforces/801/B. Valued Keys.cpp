/*
 * FILE: B. Valued Keys.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://codeforces.com/contest/801/problem/B
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
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
#include <map>
#include <set>

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
#define chk cout << "##########\n"

typedef long long ll;
typedef double lf;
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    char x[105], y[105];
    int lenx, leny;

    cin >> x >> y;
    lenx = strlen(x);
    leny = strlen(y);
    if (lenx != leny) {
        cout << "-1\n";
        return 0;
    }
    REP(i, lenx) {
        if (x[i] < y[i]) {
            cout << "-1\n";
            return 0;
        }

    }

    cout << y << '\n';

    return 0;
}


