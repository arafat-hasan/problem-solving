/*
 * FILE: CD-624.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/6/624.pdf
 *
 * DATE CREATED: 15-02-19 23:58:33 (+06)
 * LAST MODIFIED: 16-02-19 02:18:59 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 15-02-19     1.0         Deleted code is debugged code.
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


//////////////// BIT SET //////////////

// 2^n
#define bit(n)              (1 << (n))
// Check ith bit of integer n, 0 or 1
#define bitchk(n, i)        ((n & (1 << (i)))? 1 : 0)
//set ith bit ON of the integer n
#define bit_on(n, i)        n = (n | (1 << (i)))
//set ith bit OFF of the intger n
#define bit_off(n, i)       n = (n & ~(1 << (i)))
// Toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i)    n = (n ^ ( 1 << (i)))
// Set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i)   n = (n ^ ((-(x) ^ n) & (1 << (i))))

////////////////////////// START HERE //////////////////////////

vi v (21);
int n, nTracks, sum, ans;

void call (int pos, int total, int mask) {

    if (total > n) return;

    if (total > sum) {
        ans = mask;
        sum = total;
    }

    if (pos >= nTracks) {
        return ;
    }

    call (pos + 1, total + v[pos], mask | (1 << pos));
    call (pos + 1, total, mask);
}


int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);

    while (cin >> n >> nTracks) {
        rep (i, nTracks) cin >> v[i];
        ans = -1;
        sum = -1;
        call (0, 0, 0);

        for (int i = 0; i < nTracks; i++) {
            if ((ans >> i) % 2)
                cout << v[i] << ' ';
        }

        cout << "sum:" << sum << endl;
    }

    return 0;
}
