/*
 * FILE: 935C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 20-02-18 00:02:14 (+06)
 * LAST MODIFIED: 20-02-18 18:12:52 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 20-02-18     1.0         {{File Created}}
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset((ar), (val), sizeof((ar)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n';
    #define sp              cerr << ' ';
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << endl
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << endl
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << endl
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
#define EPS             1e-13
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

int main() {
    __FastIO;
    lf R, x1, y1, x2, y2;
    cout << "82 1928 -30264 2004 -30294\n";
    cin >> R >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision (12);
    lf distance = sqrt (pow (x2 - x1, 2) + pow (y2 - y1, 2) );
    lf r = (R + distance) / 2, m = 0, x3, y3, ans_x, ans_y;

    if (fabs (x1 - x2) < EPS) {
        x3 = x1;

        if ( (fabs (y1 - y2) < EPS) )
            return ! (cout << x1 + R / 2 << ' ' << y1 << ' ' << R / 2 << endl);

        y3 = (y2 > y1 ? y1 - R : y1 + R);
    } else if (fabs (y1 - y2) < EPS) {
        y3 = y1;
        x3 = (x2 > x1 ? x1 - R : x1 + R);
    } else {
        m = (y2 - y1) / (x2 - x1);
        x3 = sqrt ( (R * R) / ( (1 + (m * m) ) * 10000) ) * 100 + x1;
        y3 = m * sqrt ( (R * R) / (1 + (m * m) ) ) + y1;
        //x3 = 2 * x2 - x1;
        //y3 = 2 * y2 - y1;
        debug2 (m, R);
        ckk;
    }

    debug3 (distance, r, m);
    debug2 (x3, y3);
    ans_x = r > R ? x1 : (x2 + x3) / 2, ans_y = r > R ? y1 : (y2 + y3) / 2;
    cout << ans_x << ' ' << ans_y << ' ' << min (R, r) << endl;
    return 0;
}
