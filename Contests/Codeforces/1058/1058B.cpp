/*
 * FILE: 1058B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-09-18 19:15:50 (+06)
 * LAST MODIFIED: 23-09-18 19:21:14 (+06)
 *
 * VERDICT:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-09-18     1.0         Deleted code is debugged code.
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
#include <unordered_set>
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

////////////////////////// START HERE //////////////////////////

double area (int x1, int y1, int x2, int y2, int x3, int y3) {
    return (double) abs ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool check (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
            int x, int y) {
    double A = area (x1, y1, x2, y2, x3, y3) +
               area (x1, y1, x4, y4, x3, y3);
    double A1 = area (x, y, x1, y1, x2, y2);
    double A2 = area (x, y, x2, y2, x3, y3);
    double A3 = area (x, y, x3, y3, x4, y4);
    double A4 = area (x, y, x1, y1, x4, y4);
    return (A == A1 + A2 + A3 + A4);
}

int main() {
    _FastIO;
    int n, d, m, x, y;
    cin >> n >> d >> m;

    while (m--) {
        cin >> x >> y;
        bool ans = check (0, d, d, 0, n, n - d, n - d, n, x, y);
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
