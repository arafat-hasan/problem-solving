/*
 * FILE: 1118B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1118/problem/B
 *
 * DATE CREATED: 21-02-19 00:34:17 (+06)
 * LAST MODIFIED: 21-02-19 00:53:59 (+06)
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 21-02-19     1.0         Deleted code is debugged code.
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

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vi v (n);
    rep (i, n) cin >> v[i];
    vpii p (n);
    p[0].first = v[0];
    p[1].first = v[0];
    p[1].second = v[1];

    for (int i = 2; i < n; i++) {
        p[i].first = p[i - 2].first + v[i];
        p[i].second = p[i - 2].second + v[i];
    }

    for (int i = 0; i < n; i++) {
        debug2 (i, v[i]);
    }

    int cnt = 0;
    ckk;

    for (int i = 0; i < n; i++) {
        ll even = 0LL, odd = 0LL;

        if (! (i & 1)) {
            even = v[i - 1];
            even += -v[i] + v[ (n - 1) & 1 ? n - 1 : n - 2];
            odd = v[i - 2];
            odd += -v[i - 1] + v[ (n - 1) & 1 ? n - 2 : n - 1];

        } else {
            even = v[i - 1] + v[ (n - 1) & 1 ? n - 1 : n - 2] - v[i + 1 + 1];
            odd = v[i - 2] + v[ (n - 1) & 1 ? n - 1 : n - 2] - v[i + 1];
        }

        debug3 (i, even, odd);
        cnt += even == odd;
    }

    cout << cnt << endl;
    return 0;
}
