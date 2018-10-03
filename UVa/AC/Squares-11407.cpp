/*
 * FILE: Squares-11407.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/114/11407.pdf
 *
 * DATE CREATED: 03-10-18 15:21:57 (+06)
 * LAST MODIFIED: 03-10-18 18:38:55 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 03-10-18     1.0         Deleted code is debugged code.
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
#define MAX             10009

////////////////////////// START HERE //////////////////////////

vi v;
int dp[MAX];

void generateSqures (int n) {
    for (int i = 1; i <= n; i++) {
        v.pb (i * i);
    }
}

int rec (int n) {
    if (dp[n] != 0) return dp[n];

    if (n == 1) return dp[n] = 1;

    int idx = (int) (lower_bound (all (v), n) - v.begin());

    if (v[idx] != n) idx--;
    else return dp[n] = 1;

    int mn = INT_MAX;

    for (int i = 0; i <= idx; i++) {
        mn = min (mn, rec (n - v[i]) + 1);
    }

    return dp[n] = mn;
}

int main() {
    _FastIO;
    int t, n;
    generateSqures (MAX);
    cin >> t;

    while (t--) {
        cin >> n;
        cout << rec (n) << '\n';
    }

    return 0;
}
