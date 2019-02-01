/*
 * FILE: 1106B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1106/problem/B
 *
 * DATE CREATED: 31-01-19 18:52:43 (+06)
 * LAST MODIFIED: 31-01-19 20:21:50 (+06)
 *
 * VERDICT: Almost Accepted
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

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    //cout << "8 5\n8 6 2 1 4 5 7 5\n6 3 3 2 6 2 3 2\n2 8\n1 4\n4 7\n3 4\n6 10\n"
    //     << endl;
    //ckk;
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> p; vector<ll> a (n), c (n);
    rep (i, n)  cin >> a[i];
    rep (i, n) {
        cin >> c[i];
        p.pb ({c[i], i});
    }
    sort (all (p));
    ll d, t;
    rep (i, m) {
        cin >> t >> d;
        t--;
        //cout << "\n\nsorted cost\n";
        //debug2 (t, d);
        //for (ll j = 0; j < n; j++) {
        //    cout << p[j].first <<  '\t' << p[j].second << '\t' << a[p[j].second] << '\n';
        //}
        //ckk;
        ll customer = 0;
        //debug2 (a[t], d);

        if (a[t] >= d) {
            a[t] -= d;
            customer = d * c[t];
            //cout << "first\n";

        } else {
            d -= a[t];
            customer = a[t] * c[t];
            a[t] = 0;
            //debug3 (a[t], customer, d);

            for (ll j = 0; j < (int) p.size(); j++) {
                ll idx = p[j].second;

                if (a[idx] > 0) {
                    ll diff;

                    if (a[idx] >= d) diff = d;
                    else diff = a[idx];

                    d -= diff;
                    a[idx] -= diff;
                    //debug3 (idx, diff, d);
                    customer += (diff * c[idx]);

                } else {
                    //p.erase (p.begin() + j);
                }
            }

            if (d != 0) customer = 0;
        }

        cout << customer << '\n';
    }
    return 0;
}
