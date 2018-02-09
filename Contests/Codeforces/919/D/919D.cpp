/*
 * FILE: 919D.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 31-01-18 20:15:09 (+06)
 * LAST MODIFIED: 31-01-18 20:15:11 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 31-01-18     1.0         {{File Created}}
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
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

vi adj[30];
int vis[30], ans = -INF;
string path, val;
vi occr (30);

void dfs (int s, int p) {
    debug2 (s + 1, p + 1);
    vis[s] = 1;
    occr[ (int) val[s]]++;

    for (int i : adj[s]) {
        if (p == i) continue;

        if (vis[i] == 1) {
            cout << "-1\n";
            exit (0);
        }

        occr[ (int) val[i]]++;
        dfs (i, s);
        int mx = -INF;

        for (int j = 0; i < 26; i++) {
            mx = max (mx, occr[j]);
        }

        ans = max (ans, mx);
        debug1 (ans);
        occr[val[i]]--;

        if (occr[val[i]] < 0) occr[val[i]] = 0;
    }
}

int main() {
    __FastIO;
    int n, m, a, b;
    cin >> n >> m >> val;
    rep (i, m) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb (b);
    }

    for (int i = 0; i < n; i++) {
        clr (vis);

        for (int j = 0; j < 30; j++) occr[j] = 0;

        dfs (i, -1);
    }

    cout << ans << endl;
    return 0;
}


