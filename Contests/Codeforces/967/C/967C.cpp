/*
 * FILE: 967C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29-04-18 21:28:13 (+06)
 * LAST MODIFIED: 29-04-18 22:07:02 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 29-04-18     1.0         {{File Created}}
 *
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = a; i <= b; i++)
#define rof(i, b, a)    for (__typeof (a) i = b; i >= a; i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < n; i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "###############\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //10e7

////////////////////////// START HERE //////////////////////////


int main() {
    __FastIO;
    int n, m, st, el, q, x1, y1, x2, y2;
    double v;
    cin >> n >> m >> st >> el >> v;
    vi s (st), e (el);
    rep (i, st) cin >> s[i], s[i]--;
    rep (i, el) cin >> e[i], e[i]--;
    sort (all (s) );
    sort (all (e) );
    cin >> q;

    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        ll ele_path = 10e17;
        ll st_path = 10e17;

        // elavator
        if (el > 0) {
            auto up = upper_bound (all (e), y1);
            int pos = (int) (up - e.begin() );
            //
            //
            // right
            ll right_path = 10e17;

            if (pos != (int) e.size() ) {
                right_path = e[pos] - y1;

                if (y2 >= e[pos]) {
                    right_path += (y2 - e[pos]);

                } else {
                    right_path += (e[pos] - y2);
                }

                right_path += ( (int) ( (ceil) (abs (x2 - x1) / v) ) );
            }

            // left
            ll left_path = 10e17;

            if (pos - 1 >= 0) {
                left_path = y1 - e[pos - 1];

                if (y2 >= e[pos - 1]) {
                    left_path += (y2 - e[pos - 1]);

                } else {
                    left_path += (e[pos - 1] - y2);
                }

                left_path += ( (int) ( (ceil) (abs (x2 - x1) / v) ) );
            }

            ele_path = min (right_path, left_path);
        }

        // stair
        if (st > 0) {
            auto up = upper_bound (all (s), y1);
            int pos = (int) (up - s.begin() );
            // right
            ll right_path = 1e17;

            if (pos != (int) s.size() ) {
                right_path = s[pos] - y1;

                if (y2 >= s[pos]) {
                    right_path += (y2 - s[pos]);

                } else {
                    right_path += (s[pos] - y2);
                }

                right_path += ( (int) abs (x2 - x1) );
            }

            // left
            ll left_path = 10e17;

            if (pos - 1 >= 0) {
                left_path = y1 - s[pos - 1];

                if (y2 >= s[pos - 1]) {
                    left_path += (y2 - s[pos - 1]);

                } else {
                    left_path += (s[pos - 1] - y2);
                }

                left_path += (int) abs (x2 - x1);
            }

            //debug2 (right_path, left_path);
            st_path = min (right_path, left_path);
        }

        ll path = min (st_path, ele_path);
        cout << path << '\n';
    }

    return 0;
}


