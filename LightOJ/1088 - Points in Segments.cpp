/*
 * FILE: 1088 - Points in Segments.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: lightoj.com/volume_showproblem.php?problem=1088
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    06 Apr 2017    New             1.0		AC
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

/***************____________BIT_OPERATIONS____________***************/
// #define bit(n) (1 << (n))
// //check ith bit of integer n, 0 or 1
// #define bitchk(n, i) ((n & (1 << i))? 1 : 0)
// #define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
// #define bit_off(n, i) (n & ~(1 << i))//set ith bit OFF of the intger n
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
#define ln cout << endl;
#define sp cout << " ";
#define chk cout << "##########\n"

#define INF INT_MAX
#define MAXN 32001
#define PI acos(-1.0)
#define MAXS 100000000


typedef long long ll;
typedef double lf;
using namespace std;

int lower_bound(int *arr, int size, int value) {
    int lo = 0, hi = size - 1, mid = (lo + hi) / 2, loB = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid] == value) {
            hi = mid - 1;
            loB = mid;
        } else if (arr[mid] > value) hi = mid - 1;
        else lo = mid + 1;
    }
    if (loB == -1) return (hi + 2);
    return (loB  + 1);
}

int upper_bound(int *arr, int size, int value) {
    int lo = 0, hi = size - 1, mid = (lo + hi) / 2, upB = size;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid] == value) {
            hi = mid - 1;
            upB = mid;
        } else if (arr[mid] > value) hi = mid - 1;
        else lo = mid + 1;
    }
    if (upB == size) return (lo + 0);
    return (upB  + 1);
}

int main() {


    int T, n, q, p[100000], a, b, cs = 0;
    sf(T);
    while (T--) {
        sf(n); sf(q);
        REP(i, n) sf(p[i]);
        printf("Case %d:\n",  ++cs);
        REP(i, q) {
            sf(a); sf(b);
            printf("%d\n",  upper_bound(p, n, b) -  lower_bound(p, n, a) + 1);
        }
    }
    return 0;

}


