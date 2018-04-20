/*
 * FILE: 931D.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04-03-18 22:34:38 (+06)
 * LAST MODIFIED: 04-03-18 22:34:41 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 04-03-18     1.0         {{File Created}}
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
#define MAX             100005 //1e5+5

////////////////////////// START HERE //////////////////////////


vector<int> adj [MAX], level[MAX]; // for BFS & bfs_vis
int cost[MAX]; // for BFS & bfs_vis
vector<bool> val (MAX, 1);

int bfs (int s, int n) {
    int i, cn, v, sz;

    for (i = 0; i < n; i++)
        cost[i] = INT_MAX;

    queue<int> Q;
    Q.push (s);
    cost[s] = 0;

    while (!Q.empty() ) {
        cn = Q.front();
        Q.pop();
        sz = (int) adj[cn].size();

        for (i = 0; i < sz; i++) {
            v = adj[cn][i];

            if (cost[cn] + 1 < cost[v]) {
                Q.push (v);
                cost[v] = cost[cn] + 1;
            }
        }
    }

    return 0;
}

int main() {
    __FastIO;
    int n, tmp;
    cin >> n;
    rep (i, n - 1) {
        cin >> tmp;
        tmp--;
        adj[i + 1].pb (tmp);
        adj[tmp].pb (i + 1);
    }
    bfs (0, n);

    for (int i = 0; i < n; i++) {
        level[cost[i]].pb (i);
        debug2 (i, cost[i]);
    }

    for (int j = 0; j < n; j++)
        for (int i = 0; i < sz (level[j]); i++) {
            debug2 (j, level[j][i]);
        }

    for (int i = 0; i < n; i++) {
        if (val[0] == 1) ans++;

        int tmp = cost[i];
        int sum = 0;
        for (int j = 0; j < sz (level[tmp]); j++) {
            sum += val[level[tmp][j]];
        }
        if(sum&1) sum = 1;
        else sum = 0;
        val[i]
    }

    return 0;
}


