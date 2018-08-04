/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://algo.codemarshal.org/contests/bacsrpc18/problems/B
 *
 * DATE CREATED: 20-07-18 16:18:17 (+06)
 * LAST MODIFIED: 20-07-18 17:37:15 (+06)
 *
 * VERDICT:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 20-07-18     1.0         Deleted code is debugged code.
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
#include <unordered_set>
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
#define MAX             100007 //1e5+7

////////////////////////// START HERE //////////////////////////

int t, n, p, arr[MAX], dep[MAX], ans, ed;

int foo (int pos) {
    int val  = arr[pos];
    int idx_lo = (int) (lower_bound (dep, dep + n, val) -  dep);
    idx_lo--;
    ed = idx_lo;

    if (idx_lo == -1) return INF;

    return val - dep[idx_lo];
}

void findPlatform () {
    int plat_needed = 1, result = p - 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
            debug3 (plat_needed, i - 1, arr[i - 1]);
            int k = 1;
            int plat_cnt = plat_needed;
            int len = 0;

            if (plat_needed > result) {
                ans = 0;
                break;
            }

            int tmp;

            ckk;
            while (true) {
                int curr = i + k - 2;
                int tmp1 = foo (i - k);
                int tmp2 = arr[curr + k] - arr[curr];
                debug1(curr);

                if (tmp2 < 0) tmp2 = INF;

                if (tmp1 < tmp2) {
                    tmp = tmp1;
                    len += tmp;

                } else {
                    tmp = tmp2;
                    len += tmp;
                }

                debug3 (tmp1, tmp2, tmp);
                debug1 (len);

                if (tmp < INF) {
                    plat_cnt++;

                    if (plat_cnt == result + 1) {
                        //len = arr[st] - dep[end];
                        break;
                    }

                } else {
                    break;
                }

                k++;
            }

            debug1 (len);
            ckk;
            ans = min (ans, len);

        } else {
            plat_needed--;
            j++;
        }
    }
}

int main() {
    _FastIO;
    int cs = 0;
    cin >> t;

    while (t--) {
        cin >> n >> p;
        ans = INF;
        rep (i, n) {
            cin >> arr[i] >> dep[i];
        }
        sort (arr, arr + n);
        sort (dep, dep + n);
        findPlatform();
        cout << "Case " << ++cs << ": " << ans << endl;
        cout << "@@@@@@@@@@@@@@@@2\n";
    }

    return 0;
}
