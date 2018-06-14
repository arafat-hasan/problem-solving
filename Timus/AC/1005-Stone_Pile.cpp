/*
 * FILE: 1005-Stone_Pile.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://acm.timus.ru/problem.aspx?space=1&num=1005
 *
 * DATE CREATED: 13-06-18 20:59:35 (+06)
 * LAST MODIFIED: 13-06-18 23:41:39 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 13-06-18     1.0         Deleted code is debugged code.
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
 */

///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <vector>
#include <tuple>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>
#include <unistd.h> // unsigned int sleep(unsigned int seconds);

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef long double         llf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vl;

#define _USE_MATH_DEFINES

#define _FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(a, val)    memset((a), (val), sizeof((a)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n'
    #define sp              cerr << ' '
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << '\n'
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << '\n'
#else
    #define nl
    #define sp
    #define ckk
    #define debug1(x)
    #define debug2(x, y)
    #define debug3(x, y, z)
#endif

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //1e7+7

// 2^n
#define bit(n)              (1 << (n))
// Check ith bit of integer n, 0 or 1
#define bitchk(n, i)        ((n & (1 << (i)))? 1 : 0)
//set ith bit ON of the integer n
#define bit_on(n, i)        n = (n | (1 << (i)))
//set ith bit OFF of the intger n
#define bit_off(n, i)       n = (n & ~(1 << (i)))
// Toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i)    n = (n ^ ( 1 << (i)))
// Set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i)   n = (n ^ ((-(x) ^ n) & (1 << (i))))

////////////////////////// START HERE //////////////////////////

//int n, w[21], total = 0;

//int main() {
//    _FastIO;
//    cin >> n;
//    rep (i, n) cin >> w[i], total += w[i];
//    int lim = bit (n) - 1, mini = INF, mask = 0;

//    while (mask < lim) {
//        int sum = 0;

//        for (int i = 0; i < n; i++) {
//            if (bitchk (mask, i) )
//                sum += w[i];
//        }

//        mini = min (mini, abs (sum - total + sum) );
//        mask++;
//    }

//    cout << mini << '\n';
//    return 0;
//}


int64_t Stone[22][1000000];
int64_t inum;

int64_t stone_pile (int64_t i, int64_t C, int64_t A[]) {
    if (i >= inum)
        return Stone[i][C];
    else if (A[i] > C) {
        if (Stone[i][C] == 0) {
            Stone[i][C] = stone_pile (i + 1, C, A);
            return Stone[i][C];

        } else return Stone[i][C];

    } else {
        if (Stone[i][C] == 0) {
            Stone[i][C] = max (stone_pile (i + 1, C, A), stone_pile (i + 1, C - A[i],
                               A) + A[i]);
            return Stone[i][C];

        } else return Stone[i][C];
    }
}

int main() {
    int64_t sum = 0, mid, optimal;
    cin >> inum;
    int64_t A[inum];

    for (int i = 0; i > A[i]; i++) {
        sum = sum + A[i];
    }

    if (sum % 2 == 0) mid = sum / 2;
    else mid = sum / 2 + 1;

    optimal = stone_pile (0, mid, A);
    cout << abs (sum - optimal * 2);
    return 0;
}
