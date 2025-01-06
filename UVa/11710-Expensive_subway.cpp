/*
 * FILE: Expensive_subway-11710.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03-08-17 01:13:18 (BST)
 * LAST MODIFIED: 03-08-17 02:12:56 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 03-08-17     1.0         File Created, Accepted
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
#define MAX             401

////////////////////////// START HERE //////////////////////////

struct edge {
    int u, v, w;
};

bool compair(edge a, edge b) {
    return a.w < b.w;
}

vector<edge> e;
int parent[MAX];

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return x;
}

int Union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[px] = py;
        return 1;
    }
    return 0;
}

int main() {
    __FastIO;
    int s, c, tmp;
    string str1, str2, home;
    while (cin >> s >> c) {
        if (s == 0 and c == 0) break;

        map<string, int> mp;
        Rep(i, s) {
            cin >> str1;
            mp[str1] = i;
        }

        Rep(i, c) {
            cin >> str1 >> str2 >> tmp;
            edge get;
            get.u = mp[str1]; get.v = mp[str2]; get.w = tmp;
            e.pb(get);
        }
        cin >> home;

        make_set(s);

        sort(all(e), compair);
        int sz = (int) e.size(), cnt = 0, max = 0;
        int groups = s;

        for (int i = 0; i < sz; i++) {
            if (Union(e[i].u, e[i].v)) {
                max += e[i].w;
                cnt++;
                groups--;
                if (cnt == s - 1) break;
            }
        }

        if (groups > 1) cout << "Impossible\n";
        else cout << max << '\n';
        e.clear();
    }
    return 0;
}

