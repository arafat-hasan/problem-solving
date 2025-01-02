/*
 * FILE: 910B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-12-17 12:57:49 (+06)
 * LAST MODIFIED: 25-12-17 00:35:58 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-12-17     1.0         File Created, Accepted
 *
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = a; i <= b; i++)
#define rof(i, b, a)    for (__typeof (a) i = b; i >= a; i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < n; i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "###############\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //10e7

////////////////////////// START HERE //////////////////////////

// Accepted
//int main() {
//    __FastIO;
//    int n, a, b;
//    cin >> n >> a >> b;
//    int verticle = 0, horizontal = 0;
//    int bar = 0;
//    int cnt (0);

//    while (verticle < 4 or horizontal < 2) {
//        debug3 (bar, verticle, horizontal);

//        if ( (bar < a or verticle == 4) and (bar < b or horizontal == 2) ) {
//            bar = n;
//            cnt++;
//        }

//        if (bar >= a and verticle != 4) {
//            bar -= a;
//            verticle++;
//        }

//        if (bar >= b and horizontal != 2) {
//            bar -= b;
//            horizontal++;
//        }
//    }

//    cout << cnt << endl;
//    return 0;
//}




int dp[10][10][1010], n, a, b;

int fun (int ver, int hor, int now) {
    if (ver == 0 and hor == 0)
        return 1;

    int r1 = INF, r2 = INF;

    if (dp[ver][hor][now] != -1)
        return dp[ver][hor][now];

    if (ver) {
        if (now - a < 0)
            r1 = fun (ver - 1, hor, n - a) + 1;
        else r1 = fun (ver - 1, hor, now - a);
    }

    if (hor) {
        if (now - b < 0)
            r2 = fun (ver, hor - 1, n - b) + 1;
        else r2 = fun (ver, hor - 1, now - b);
    }

    return dp[ver][hor][now] = min (r1, r2);
}

int main() {
    fill (dp, -1);
    cin >> n >> a >> b;
    int ans = fun (4, 2, n);
    cout << ans << endl;
    return 0;
}
