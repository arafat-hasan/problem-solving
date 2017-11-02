/*
 * FILE: /media/Softwares/Programming/ACM/Contests/Codeforces/884/C/C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 27-10-17 21:23:43 (+06)
 * LAST MODIFIED: 28-10-17 00:46:46 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 27-10-17     1.0         File Created, Accepted
 *
 *
 *
 *                 ██╗███████╗███╗   ██╗██╗███╗   ██╗
 *                 ██║██╔════╝████╗  ██║██║████╗  ██║
 *                 ██║█████╗  ██╔██╗ ██║██║██╔██╗ ██║
 *            ██   ██║██╔══╝  ██║╚██╗██║██║██║╚██╗██║
 *            ╚█████╔╝███████╗██║ ╚████║██║██║ ╚████║
 *             ╚════╝ ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝
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

#define forr(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

int parent[100001];

void Make_Set(int x) {
    parent[x] = x;
}

int Find(int x) {
    if (x != parent[x]) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y) {
    int PX = Find(x), PY = Find(y);
    parent[PX] = PY;
}

int main() {
    __FastIO;
    int n, p;
    cin >> n;
    map<int, int> map;
    vector<int> v;
    rep(i, n) Make_Set(i);

    rep(i, n) {
        cin >> p;
        p--;
        if (Find(i) != Find(p))
            Union(p, i);
    }

    rep(i, n) int tmp = Find(i);
    for (int i = 0; i < n; i++) {
        //debug2(i, parent[i]);
        map[parent[i]]++;
    }

    forit(i, map) {
        //debug2(i->first, i->second);
        v.pb(i->second);
    }

    sort(all(v), greater<int>());
    //forit(i, v) debug1(*i);
    if (v.size() == 1) {
        cout << ((ll) v[0] * (ll) v[0]) << endl;
        return 0;
    }

    ll sum = ((ll) v[0] + (ll) v[1]) * ((ll) v[0] + (ll) v[1]);

    for (int i = 2; i < (int) v.size(); i++) {
        sum += ((ll)v[i] * (ll)v[i]);
    }

    cout << sum << endl;
    return 0;
}

