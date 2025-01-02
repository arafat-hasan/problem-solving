/*
 * FILE: 777B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 27-12-17 15:51:24 (+06)
 * LAST MODIFIED: 27-12-17 20:39:06 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 27-12-17     1.0         File Created, Accepted
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

#define forr(i, a, b)   for (__typeof (a) i = a; i <= b; i++)
#define rof(i, b, a)    for (__typeof (a) i = b; i >= a; i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < n; i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n';
    #define sp              cerr << ' ';
    #define ckk             cout << "###############\n"
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
#define MAX             10000007 //10e7

////////////////////////// START HERE //////////////////////////

int main() {
    __FastIO;
    int n;
    string s, m;
    cin >> n >> s >> m;
    map<char, int> _m, __m, _s, __s;
    rep (i, n) _m[m[i]]++;
    rep (i, n) _s[s[i]]++;
    __m = _m;
    int cnt = 0;

    for (char i = '0'; i <= '9'; i++) {
        int tmp = _s[i];

        for (char j = (char) (i); j <= '9' and tmp > 0; j++) {
            if (_m[j] >= tmp) {
                _m[j] -= tmp;
                tmp -= tmp;
            } else {
                tmp -= _m[j];
                _m[j] -= _m[j];
            }
        }

        if (tmp != 0) cnt += tmp;
    }

    cout << cnt << endl;
    cnt = 0;

    for (char i = '0'; i <= '9'; i++) {
        int tmp = _s[i];

        for (char j = (char) (i + 1); j <= '9' and tmp > 0; j++) {
            if (__m[j] >= tmp) {
                __m[j] -= tmp;
                cnt += tmp;
                tmp -= tmp;
            } else {
                cnt += __m[j];
                tmp -= __m[j];
                __m[j] -= __m[j];
            }
        }
    }

    cout << cnt << endl;
    return 0;
}


