/*
 * FILE: The_Grand_Dinner-10249.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 18-07-17 01:17:42 (BST)
 * LAST MODIFIED: 18-07-17 17:32:09 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 18-07-17     1.0         File Created, Accepted
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


int main() {
    __FastIO;
    int m, n, k, tmp;
    bool fl;
    while (cin >> m >> n and m and n) {
        vi tm(m), v[m];
        vpii tbl;
        Rep(i, m) cin >> tm[i];
        Rep(i, n) {
            cin >> tmp;
            tbl.pb(make_pair(tmp, i));
        }

        sort(all(tbl), greater<pii>());
        fl = true;
        Rep(i, m) {
            for (int j = 0; j < tm[i]; j++ ) {
                fl = false;
                for (k = 0; k < n; k++) {
                    if (tm[i] <= 0) break;
                    if (tbl[k].first > 0) {
                        v[i].pb(tbl[k].second);
                        tm[i]--;
                        tbl[k].first--;
                    }
                }
                if (tm[i] != 0) {
                    fl = true;
                    break;
                }
            }
            if (fl) break;
        }
        if (fl) cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            Rep(i, m) {
                int sz = (int) v[i].size();
                sort(all(v[i]));
                Rep(j, sz) {
                    cout << v[i][j] + 1 << ' ';
                }
                nl;
            }
        }
    }
    return 0;
}

