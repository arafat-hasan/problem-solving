/*
 * FILE: C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-11-17 21:58:14 (+06)
 * LAST MODIFIED: 23-11-17 23:17:53 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-11-17     1.0         {{File Created}}
 *
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

int cost[100005];
int parent[100005];
int mincost[100005];

void Make_Set(int x) {
    parent[x] = x;
}

int Find(int x) {
    if (x != parent[x]) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int &x, int &y) {
    int PX = Find(x), PY = Find(y);
    parent[PX] = PY;
}

int main() {
    __FastIO;
    int n, m, u, v;
    cin >> n >> m;
    rep(i, n) cin >> cost[i];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        if (Find(u) != Find(v)) {
            Union(u, v);
        }
    }
    //for (int i = 0; i < n; i++) Find(i);
    rep(i, n) mincost[i] = INF;

    for (int i = 0; i < n; i++) {
        int p = Find(i);
        if (mincost[p] > cost[i]) {
            mincost[p] = cost[i];
        }
    }

    ll sum = 0L;
    for (int i = 0; i < n; i++) {
        if (mincost[i] != INF)
            sum += mincost[i];
    }
    cout << sum << endl;
    return 0;
}

