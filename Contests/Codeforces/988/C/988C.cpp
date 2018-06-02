/*
 * FILE: 988C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01-06-18 21:38:43 (+06)
 * LAST MODIFIED: 01-06-18 22:24:26 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 01-06-18     1.0         {{File Created}}
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
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

struct foo {
    int id, idx;
    ll sum;
};

inline bool operator< (const foo &lhs, const foo &rhs) {
    return lhs.sum < rhs.sum;
}


int main() {
    _FastIO;
    int k, n, id = 0;
    cin >> k;
    vector<set<foo>> pr;

    while (k--) {
        cin >> n;
        vi v (n);
        ll sum = 0;
        rep (i, n) cin >> v[i], sum += (ll) v[i];
        set<foo> st;

        for (int i = 0; i < n; i++) {
            ll tmp = sum - (ll) v[i];
            st.insert ({id, i, tmp});
        }

        pr.push_back (st);
        id++;
    }

    set<foo> bucket;
    bool flag = false;
    int ans_id1, ans_id2, ans_idx1, ans_idx2;

    for (int i = 0; i < (int) pr.size(); i++) {
        for (set<foo> :: iterator it = pr[i].begin(); it != pr[i].end(); ++it) {
            //debug3 ( (*it).sum, (*it).id, (*it).idx);
            if (bucket.count (*it) != 0) {
                flag = true;
                ans_id1 = (*it).id;
                ans_idx1 = (*it).idx;
                auto next = bucket.find (*it);
                ans_id2 = (*next).id;
                ans_idx2 = (*next).idx;
                goto ans_sec;

            } else {
                bucket.insert (*it);
            }
        }
    }

ans_sec:

    if (flag) {
        cout << "YES\n";
        cout << ans_id1 + 1 << ' ' << ans_idx1 + 1 << '\n';
        cout << ans_id2 + 1 << ' ' << ans_idx2 + 1 << '\n';

    } else {
        cout << "NO\n";
    }

    return 0;
}


