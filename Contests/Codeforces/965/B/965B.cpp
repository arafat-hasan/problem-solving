/*
 * FILE: 965B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 25-04-18 23:54:28 (+06)
 * LAST MODIFIED: 26-04-18 00:08:24 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 25-04-18     1.0         {{File Created}}
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

int ala[101][101];

int main() {
    __FastIO;
    int n, k;
    char mat[101][101];
    cin >> n >> k;
    rep (i, n) {
        rep (j, n) {
            cin >> mat[i][j];
        }
    }
    rep (i, n) {
        rep (j, n) {
            if (mat[i][j] == '.') {
                // horizontally
                int cnt = 0;

                for (int m = j; m < n; m++) {
                    if (mat[i][m] == '.') cnt++;
                    else break;

                    if (cnt == k) break;
                }

                if (cnt == k) {
                    for (int m = j; cnt ; m++, cnt--) {
                        ala[i][m]++;
                    }
                }

                //vertically
                cnt = 0;

                for (int m = i; m < n; m++) {
                    if (mat[m][j] == '.') cnt++;
                    else break;

                    if (cnt == k) break;
                }

                if (cnt == k) {
                    for (int m = i; cnt; m++, cnt--) {
                        ala[m][j]++;
                    }
                }
            }
        }
    }
    int mx = -INF, r = 0, c = 0;
    rep (i, n) {
        rep (j, n) {
            if (mx < ala[i][j]) {
                mx = ala[i][j];
                r = i;
                c = j;
            }
        }
    }
    cout << r + 1 << ' ' << c + 1 << endl;
    return 0;
}


