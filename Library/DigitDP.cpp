/*
 * FILE: DigitDP.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://github.com/flash7even/Programming-Contest/blob/master/Code%20Repository/Dynamic%20Programming/Digit%20DP/Digit-DP.cpp
 *
 * DATE CREATED: 28-01-19 20:30:37 (+06)
 * LAST MODIFIED: 28-01-19 20:31:24 (+06)
 *
 * VERDICT: Almost Accepted
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

/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

vector<int> num;
int a, b, d, k;
int DP[12][12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call (int pos, int cnt, int f) {
    if (cnt > k) return 0;

    if (pos == (int) num.size()) {
        if (cnt == k) return 1;

        return 0;
    }

    if (DP[pos][cnt][f] != -1) return DP[pos][cnt][f];

    int res = 0;
    int LMT;

    if (f == 0) {
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];

    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for (int dgt = 0; dgt <= LMT; dgt++) {
        int nf = f;
        int ncnt = cnt;

        if (f == 0
            && dgt < LMT) nf = 1; /// The number is getting smaller at this position

        if (dgt == d) ncnt++;

        if (ncnt <= k) res += call (pos + 1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve (int b) {
    num.clear();

    while (b > 0) {
        num.push_back (b % 10);
        b /= 10;
    }

    reverse (num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity
    memset (DP, -1, sizeof (DP));
    int res = call (0, 0, 0);
    return res;
}

int main () {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    cin >> a >> b >> d >> k;
    int res = solve (b) - solve (a - 1);
    cout << res << endl;
    return 0;
}
