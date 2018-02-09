/*
 * FILE: 913C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 08-01-18 21:35:31 (+06)
 * LAST MODIFIED: 08-01-18 22:47:10 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 08-01-18     1.0         {{File Created}}
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
#define EPS             1e-7
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

//ll c[31], l, n, v[31];
////ll dp[31][]

//ll fun (ll i, ll amn) {
//    debug2(i, amn);
//    if (amn >= l) return 1;

//    if (i == n) return 1e18;

//    ll ret1 = fun (i + 1, amn + v[i]) + c[i];
//    ll ret3 = fun (i + 1, amn);
//    ll ret2 = fun (i, amn + v[i]) + c[i];
//    return min (ret1, min (ret2, ret3) );
//}

//int main() {
//    __FastIO;
//    cin >> n >> l;
//    rep (i, n) cin >> c[i];
//    rep (i, n) v[i] = (ll) pow (2, i);
//    cout << fun (0, 0) - 1 << endl;
//    return 0;
//}

struct foo {
    ll c, s;
    double g;
};

bool comp (foo a, foo b) {
    if (a.g < b.g) return true;

    return false;
}

int main() {
    __FastIO;
    ll n, l, c, s;
    double g;
    foo tmp;
    cin >> n >> l;
    vector<foo> v;
    rep (i, n) {
        cin >> c;
        s = (int) pow (2, i);
        g = (double) c / (double) s;
        tmp.c = c; tmp.s = s; tmp.g = g;
        v.pb (tmp);
    }
    sort (all (v), comp );

    for (auto i : v) cout << i.c << '\t'; nl;

    for (auto i : v) cout << i.s << '\t'; nl;

    for (auto i : v) cout << i.g << '\t'; nl;

    ll min = INF, tmp_min;

    for (int i = 0; i < n; i++) {
        ll tm = (int) (l / v[i].s);
        tmp_min = v[i].c * tm;
        ll baki = l - v[i].s;
        debug2 (baki, tm);

        for (int j = i; j < n; j++) {
            tm = (int) (baki / v[j].s);

            if (tm > 0) baki = (baki - v[j].s * tm);

            if (baki <= 0) {
                if (min > tmp_min) min = tmp_min;
            }
        }

        if (min > tmp_min and baki <= 0) min = tmp_min;
    }

    cout << min << endl;
    return 0;
}
