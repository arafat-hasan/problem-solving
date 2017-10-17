/*
 * FILE: 1002-Country_Roads.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 31-07-17 14:46:09 (BST)
 * LAST MODIFIED: 01-08-17 21:52:06 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 31-07-17     1.0         File Created, AC
 *
 */


/*
//     ___          ___           ___                       ___
//    /  /\        /  /\         /__/\        ___          /__/\
//   /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
//  /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
//  \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
//     \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
//      \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
//      /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
//     /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
//     \__\/      \  \::/       \  \:\         \__\/      \  \:\
//                 \__\/         \__\/                     \__\/
*/

/////////////////////////////////////////////////////////////////////////////

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

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cout << #x << ": " << x << endl
#define debug2(x, y)    cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-10
#define MAXN            503
#define MAX             1010

////////////////////////// START HERE //////////////////////////


struct edge {
    int u, v, w;
};

bool compair(edge a, edge b) {
    return a.w < b.w;
}


vector<edge> e;
int parent[MAXN];
int cost[MAXN]; // cost to run along bfs tree;
int ans[MAXN]; // store answer, max cost from home
vector<int> adj[MAX];
map<pii, int> mp; // store all given node to node cost

void bfs(int s, int n) {
    int cn, sz, v;
    for (int i = 0; i < n; i++) {
        cost[i] = INF;
        ans[i] = -INF;
    }

    queue<int> Q;
    Q.push(s);
    cost[s] = 0;
    ans[s] = 0;
    while (!Q.empty()) {
        cn = Q.front();
        Q.pop();
        sz = (int) adj[cn].size();
        for (int i = 0; i < sz; i++) {
            v = adj[cn][i];
            if (cost[cn] + 1 < cost[v]) {
                Q.push(v);
                cost[v] = cost[cn] + 1;
                ans[v] = max(mp[make_pair(cn, v)], ans[cn]);
            }
        }
    }
}



int find(int x) {
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return x;
}


void minimum_spanning_tree(int n) {

    sort(all(e), compair);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int sz = (int) e.size(), cnt = 0;

    for (int i = 0; i < sz; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            parent[u] = v;
            adj[e[i].u].pb(e[i].v);
            adj[e[i].v].pb(e[i].u);
            mp[make_pair(e[i].u, e[i].v)] = e[i].w;
            mp[make_pair(e[i].v, e[i].u)] = e[i].w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
}

int main() {
    //__FastIO;
    int t, n, m, home, cs = 0;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        Rep(i, m) {
            edge get;
            cin >> get.u >> get.v >> get.w;
            e.pb(get);
        }
        cin >> home;

        // Make MST tree
        minimum_spanning_tree(n);

        // Run bfs over MST tree
        bfs(home, n);

        cout << "Case " << ++cs << ":\n";
        Rep(i, n) {
            if (ans[i] == -INF) cout << "Impossible\n";
            else cout << ans[i] << '\n';
        }

        e.clear();
        Rep(i, MAX) adj[i].clear();
        mp.clear();
    }
    return 0;
}

