/*
 * FILE: 1140-How_many_Zeros.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://lightoj.com/volume_showproblem.php?problem=1140
 *
 * DATE CREATED: 28-01-19 20:41:24 (+06)
 * LAST MODIFIED: 30-01-19 00:19:11 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 28-01-19     1.0         Deleted code is debugged code.
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
ll dp[33][33][2][2];
int d = 0; // Here is d is which digit to count, in this problem we have to count zero
/// dp[p][c][f][z] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// small = the number we are building has already become smaller than b? [0 = no, 1 = yes]
/// z = avoid to count initial zeros


ll call (int pos, ll cnt, bool small, bool anyNonZero) {
    if (pos == (int) num.size()) return cnt;

    if (dp[pos][cnt][small][anyNonZero] != -1)
        return dp[pos][cnt][small][anyNonZero];

    ll res = 0; int lmt;
    /// Digits we placed so far matches with the prefix of b
    /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
    /// The number has already become smaller than b. We can place any digit now.
    lmt = (small ? 9 : num[pos]);

    /// Try to place all the valid digits such that the number doesn't exceed b
    for (int dgt = 0; dgt <= lmt; dgt++) {
        ll ncnt = cnt;
        bool fAnyNonZero = anyNonZero, fSmall =  small;

        if (small == 0 and dgt < lmt)
            fSmall = 1; /// The number is getting smaller at this position

        fAnyNonZero = dgt > 0 ? true : fAnyNonZero;

        if (dgt == d and fAnyNonZero) ncnt++;

        res += call (pos + 1, ncnt, fSmall, fAnyNonZero);
    }

    return dp[pos][cnt][small][anyNonZero] = res;
}

ll solve (ll n) {
    if (n < 0) return 0;

    num.clear();

    while (n > 0) {
        num.push_back ((int) (n % 10));
        n /= 10;
    }

    reverse (num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity
    memset (dp, -1, sizeof (dp));
    ll res = call (0, 0, 0, 0);
    return res + 1;
}

int main () {
    ios_base::sync_with_stdio (false);
    //cin.tie (0); /// LightOJ does not accepted cin.tie(), runtime error given
    cout.tie (0);
    ll t, n, m, cs = 0;
    cin >> t;

    while (t--) {
        cin >> m >> n;
        ll res = solve (n) - solve (m - 1);
        cout << "Case " << ++cs << ": " << res << '\n';
    }

    return 0;
}
