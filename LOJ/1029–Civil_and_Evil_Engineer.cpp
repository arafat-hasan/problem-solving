/*
 * FILE: 1029–Civil_and_Evil_Engineer.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 30-07-17 16:46:44 (BST)
 * LAST MODIFIED: 30-07-17 19:59:55 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 30-07-17     1.0         File Created, AC
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
#define MAXN             101

////////////////////////// START HERE //////////////////////////


struct edge {
    int u, v, w;
};

bool compair(edge a, edge b) {
    if (a.w > b.w) return false;
    return true;
}

int parent[MAXN];
vector<edge> e;

int find(int r) {
    if (parent[r] == r) return r;
    else return parent[r] = find(parent[r]);
}

void spanningtree(int n, int *mins, int *maxs) {
    sort(e.begin(), e.end(), compair);
    for (int i = 0; i <= n; i++) {
        parent[i]  = i;
    }

    int count = 0;
    *mins = 0;
    int sz = (int) e.size();
    for (int i = 0; i < sz; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            parent[u] = v;
            count++;
            *mins += e[i].w;
            if (count == n) break;
        }
    }


    reverse(e.begin(), e.end());

    for (int i = 0; i <= n; i++) {
        parent[i]  = i;
    }
    count = 0;
    *maxs = 0;
    sz = (int) e.size();
    for (int i = 0; i < sz; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            parent[u] = v;
            count++;
            *maxs += e[i].w;
            if (count == n) break;
        }
    }
}

int main() {
    __FastIO;
    int n, t, cs = 0;
    cin >> t;
    while (t--) {
        int u, v, w, mins, maxs;
        cin.ignore();
        cin >> n;
        while (cin >> u >> v >> w) {
            if ( u == 0 and v == 0 and w == 0) break;
            edge get;
            get.u = u; get.v = v; get.w = w;
            e.push_back(get);
        }
        spanningtree(n, &mins, &maxs);
        int sum = maxs + mins;
        if (sum % 2 == 0) cout << "Case " << ++cs << ": " << sum / 2 << '\n';
        else cout << "Case " << ++cs << ": " << sum << "/2\n";
        e.clear();
    }
    return 0;
}

