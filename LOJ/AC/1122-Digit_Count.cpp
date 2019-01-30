/*
 * FILE: 1122-Digit_Count.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://lightoj.com/volume_showproblem.php?problem=1122
 *
 * DATE CREATED: 30-01-19 01:04:45 (+06)
 * LAST MODIFIED: 30-01-19 02:18:13 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 30-01-19     1.0         Deleted code is debugged code.
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

vector<int> digits;
int n;
int dp[12][12][2];

int digitDP (int idx, int pre, bool anyNonZero) {
    if (idx == n) return 1;

    if (dp[idx][pre][anyNonZero] != -1) return dp[idx][pre][anyNonZero];

    int res = 0;

    for (int i = 0; i < (int) digits.size(); i++) {
        pre = (idx == 0 ? digits[i] : pre);

        if (abs (pre - digits[i]) > 2) continue;

        bool fAnyNonZero = anyNonZero;

        if (digits[i] != 0) fAnyNonZero = true;

        if (fAnyNonZero) res += digitDP (idx + 1, digits[i], fAnyNonZero);
    }

    return dp[idx][pre][anyNonZero] = res;
}

int main() {
    ios_base::sync_with_stdio (false);
    //cin.tie (0);
    cout.tie (0);
    int m, t, cs = 0, tmp;
    cin >> t;

    while (t--) {
        cin >> m >> n;

        for (int i = 0; i < m; i++) {
            cin >> tmp;
            digits.push_back (tmp);
        }

        memset (dp, -1, sizeof dp);
        cout << "Case " << ++cs << ": " << digitDP (0, digits[0], 0) << '\n';
        digits.clear();
    }

    return 0;
}
