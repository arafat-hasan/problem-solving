/*
 * FILE: 1032-Fast_Bit_Calculations.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://lightoj.com/volume_showproblem.php?problem=1032
 *
 * DATE CREATED: 31-01-19 00:17:12 (+06)
 * LAST MODIFIED: 31-01-19 00:37:24 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 31-01-19     1.0         Deleted code is debugged code.
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

vector<int> num;
ll dp[40][2][2][40];

ll digitDP (int idx, int pre, bool isSmall, ll sum) {
    if (idx == (int) num.size()) return sum;

    if (dp[idx][pre][isSmall][sum] != -1) return dp[idx][pre][isSmall][sum];

    ll res = 0;
    int lmt = isSmall ? 1 : num[idx];

    for (int dgt = 0; dgt <= lmt; dgt++) {
        res += digitDP (idx + 1, dgt, (isSmall | (dgt < num[idx])), \
                        ((pre == 1 and dgt == 1) + sum));
    }

    return dp[idx][pre][isSmall][sum] = res;
}

ll call (ll n) {
    num.clear();

    while (n > 0) {
        num.pb ((int) (n % 2));
        n /= 2;
    }

    reverse (num.begin(), num.end());
    memset (dp, -1, sizeof dp);
    return digitDP (0, 0, 0, 0);
}

int main() {
    //ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    ll t, n, cs = 0;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << "Case " << ++cs << ": " << call (n) << endl;
    }

    return 0;
}
