/*
 * FILE: train-ticket.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 02-03-18 21:05:24 (+06)
 * LAST MODIFIED: 02-03-18 21:21:09 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 02-03-18     1.0         File Created, Accepted
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

string berthType (int n) {
    vi lb, mb, ub, slb, sub;

    for (int i = 1;; ) {
        if (i > 72) break;

        lb.pb (i);

        if (i + 3 > 72) break;

        lb.pb (i + 3);
        i += 8;
    }

    for (int i = 2;; ) {
        if (i > 72) break;

        mb.pb (i);

        if (i + 3 > 72) break;

        mb.pb (i + 3);
        i += 8;
    }

    for (int i = 3;; ) {
        if (i > 72) break;

        ub.pb (i);

        if (i + 3 > 72) break;

        ub.pb (i + 3);
        i += 8;
    }

    for (int i = 7;; ) {
        if (i > 72) break;

        slb.pb (i);
        i += 8;
    }

    for (int i = 8;; ) {
        if (i > 72) break;

        sub.pb (i);
        i += 8;
    }

    if (find (all (lb), n) != lb.end() ) return "LB";

    if (find (all (mb), n) != mb.end() ) return "MB";

    if (find (all (ub), n) != ub.end() ) return "UB";

    if (find (all (slb), n) != slb.end() ) return "SLB";

    if (find (all (sub), n) != sub.end() ) return "SUB";

    return "";
}

int main() {
    __FastIO;
    int n;
    cin >> n;
    cout << berthType (n) << endl;
    return 0;
}


