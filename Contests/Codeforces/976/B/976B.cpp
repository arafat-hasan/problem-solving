/*
 * FILE: 976B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30-04-18 21:07:38 (+06)
 * LAST MODIFIED: 30-04-18 22:11:07 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 30-04-18     1.0         {{File Created}}
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
#define fill(a, val)    memset((a), (val), sizeof((a)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n'
    #define sp              cerr << ' '
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

int main() {
    __FastIO;
    ll n, m, k;
    cin >> n >> m >> k;

    if (k < n) {
        cout << k + 1 << ' ' << 1 << '\n';

    } else {
        ll foo = k - n + 1;
        ll md = foo % (m - 1);
        ll div = foo / (m - 1);
        //debug2 (n, m);
        //debug3 (foo, md, div);

        if (div & 1) {
            cout << (md != 0 ? n - div : n - div + 1) \
                 << ' ' << m - md + ( (bool) md) << '\n';

        } else {
            cout << (md != 0 ?  n - div : n - div + 1) \
                 << ' ' << md + (md == 0 ? 2 : 1) << '\n';
        }
    }

    return 0;
}


