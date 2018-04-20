/*
 * FILE: 946D.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06-03-18 22:26:36 (+06)
 * LAST MODIFIED: 07-03-18 01:25:45 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 06-03-18     1.0         {{File Created}}
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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset((ar), (val), sizeof((ar)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n';
    #define sp              cerr << ' ';
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << endl
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << endl
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << endl
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

int main() {
    __FastIO;
    int n, m, skip;
    string str[502];
    cin >> n >> m >> skip;
    rep (i, n) {
        cin >> str[i];
    }

    for (int i = 0; i < skip; i++) {
        int mx = -INF, mx_j = -1, mx_k = -1;

        for (int j = 0; j < n; j++) {
            //debug1 (str[j]);
            bool fl = false, close = false;
            int cnt = 0;
            int cnt_k = -1;

            for (int k = 0; k < m; k++) {
                if (fl == true) {
                    if (str[j][k] == '0') cnt++;
                    else {
                        close = true;
                        break;
                    }
                }

                if (str[j][k] == '1') {
                    cnt_k = k;
                    fl = true;
                }
            }

            if (fl == false) continue;

            if (close == false) cnt = 0;

            //debug2 (cnt, cnt_k);

            if (mx < cnt) {
                mx = cnt;
                mx_j = j;
                mx_k = cnt_k;
            }

            fl = false;
            cnt = 0;
            cnt_k = -1;
            close = false;

            for (int k = m - 1; k >= 0; k--) {
                if (fl == true) {
                    if (str[j][k] == '0') cnt++;
                    else {
                        close = true;
                        break;
                    }
                }

                if (str[j][k] == '1') {
                    cnt_k = k;
                    fl = true;
                }
            }

            if (close == false) cnt = 0;

            //debug2 (cnt, cnt_k);

            if (mx < cnt) {
                mx = cnt;
                mx_j = j;
                mx_k = cnt_k;
            }
        }

        debug3 (mx, mx_j, mx_k);

        if (mx_k != -1 and mx_j != -1)
            str[mx_j][mx_k] = '0';

        rep (kk, n) {
            cout << str[kk] << endl;
        }
        ckk;
    }

    int ans = 0;

    for (int j = 0; j < n; j++) {
        int left = -1, right = -1;

        for (int k = 0; k < m; k++) {
            if (str[j][k] == '1') {
                left = k;
                break;
            }
        }

        for (int k = m - 1; k >= 0; k--) {
            if (str[j][k] == '1') {
                right = k;
                break;
            }
        }

        debug3 (str[j], left, right);

        if (! (right == -1 or left == -1) ) ans += (right - left + 1);
    }

    cout << ans << endl;
    return 0;
}


