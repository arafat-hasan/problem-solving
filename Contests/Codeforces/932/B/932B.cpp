/*
 * FILE: 932B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 15-02-18 20:44:02 (+06)
 * LAST MODIFIED: 15-02-18 20:59:26 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 15-02-18     1.0         {{File Created}}
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
#define MAX             1000006 //1e6+6

////////////////////////// START HERE //////////////////////////

int bar[MAX + 6];
unordered_map< int, vector<int> > store;

int findFrequency (int left, int right, int element) {
    int a = (int) (lower_bound (store[element].begin(), store[element].end(),
                                left) -  store[element].begin() );
    int b = (int) (upper_bound (store[element].begin(), store[element].end(),
                                right) - store[element].begin() );
    return b - a;
}

int fun (int n) {
    int p = 1;

    while (n > 0) {
        int tmp = n % 10;
        p *= (tmp ? tmp : 1);
        n /= 10;
    }

    return p;
}

int main() {
    __FastIO;
    int q, l, r, k, n, cnt;

    for (int i = 1; i < MAX; i++) {
        n = i;

        while (n >= 10) {
            n = fun (n);
        }

        bar[i] = n;
        //debug2 (i, n);
    }

    int sz = sizeof (bar) / sizeof (bar[0]);

    for (int i = 0; i < sz; ++i)
        store[bar[i]].push_back (i + 1);

    cin >> q;

    while (q--) {
        cin >> l >> r >> k;
        cnt  = findFrequency (l + 1, r + 1, k);
        cout << cnt << '\n';
    }

    return 0;
}


