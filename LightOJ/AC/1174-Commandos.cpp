/*
 * FILE: 1174-Commandos.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://www.lightoj.com/volume_showproblem.php?problem=1174
 *
 * DATE CREATED: 25-09-18 19:21:23 (+06)
 * LAST MODIFIED: 25-09-18 20:24:56 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 25-09-18     1.0         Deleted code is debugged code.
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
#include <queue>
#include <deque>
#include <vector>
#include <functional>

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
#define MAX             101

////////////////////////// START HERE //////////////////////////

vector<int> adj[MAX];
int cost[MAX];

int bfs (int src, int des, int n) {
    int cn, v, sz;

    for (int i = 0; i < n; i++) {
        cost[i] = INT_MAX;
    }

    queue<int> Q;
    Q.push (src);
    cost[src] = 0;

    while (!Q.empty()) {
        cn = Q.front();
        Q.pop();
        sz = (int) adj[cn].size();

        for (int i = 0; i < sz; i++) {
            v = adj[cn][i];

            if (cost[cn] + 1 < cost[v]) {
                Q.push (v);
                cost[v] = cost[cn] + 1;

                if (v == des) return cost[v];
            }
        }
    }

    return 0;
}

int main() {
    _FastIO;
    int t, n, m, u, v, cs = 0, s, d;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        while (m--) {
            cin >> u >> v;
            adj[u].pb (v);
            adj[v].pb (u);
        }

        cin >> s >> d;
        int mx = -1;

        for (int i = 0; i < n; i++) {
            mx = max (mx, bfs (s, i, n) + bfs (i, d, n));
        }

        cout << "Case " << ++cs << ": " << mx << '\n';
        rep (i, n) adj[i].clear();
    }

    return 0;
}
