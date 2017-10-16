/*
 * FILE: IP-TV-1174.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01-08-17 21:55:11 (BST)
 * LAST MODIFIED: 01-08-17 22:26:12 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 01-08-17     1.0         File Created, Accepted
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
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

struct edge {
    int u, v, w;
};

bool compair(edge a, edge b) {
    return a.w < b.w;
}

int parent[MAX];
vector<edge> e;

int find(int x) {
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return x;
}

int mst(int n) {

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(all(e), compair);

    int cnt = 0; int s = 0;
    for (int i = 0; i < n; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            parent[u] = v;
            s += e[i].w;
            cnt++;
            if (cnt == n) break;
        }
    }
    return s;
}

int main() {
    __FastIO;
    int t, n, m, tmp;
    string str1, str2;
    map<string, int> mp;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cin.ignore();
        int cnt = 0;
        Rep(i, n) {
            cin >> str1 >> str2 >> tmp;
            if (mp.count(str1) == 0) mp[str1] = cnt++;
            if (mp.count(str2) == 0) mp[str2] = cnt++;
            edge get;
            get.u = mp[str1]; get.v = mp[str2]; get.w = tmp;
            e.pb(get);
        }

        int max = mst(n);
        cout << max << '\n';
        if(t != 0) cout << '\n';

        e.clear();
        mp.clear();
    }
    return 0;
}

