/*
 * FILE: 1130C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-02-19 22:41:43 (+06)
 * LAST MODIFIED:
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-02-19     1.0         Deleted code is debugged code.
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

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

////////////////////////// START HERE //////////////////////////

char mat[51][51];
int n, r1, c1, r2, c2;
int vis[51][51];
int ans, tx, ty;
int tt = 0;

void dfs (int sx, int sy) {
    vis[sx][sy] = 1;

    if (tx == sx and ty == sy) {
        ans = 1;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int tmpX = sx + dx[i];
        int tmpY = sy + dy[i];

        if (tmpX  >= n or tmpY >= n or tmpX < 0 or tmpY < 0) continue;

        if (mat[sx][sy] != mat[tmpX][tmpY]) continue;

        if (vis[tmpX][tmpY] == 0) {
            dfs (tmpX, tmpY);
        }
    }
}


int vis2[51][51];

int foo (int sx, int sy) {
    int bar = (sx - r2) * ( sx - r2) + (sy - c2) * (sy - c2);
    fill (vis2, -1);
    debug3 (sx, sy, 0);

    for (int i = 0, ttx = r2, tty = c2; i < (n * n); i++) {
        vis2[ttx][tty] = 1;

        for (int j = 0; j < 4; j++) {
            int tmpX = ttx + dx[j];
            int tmpY = tty + dy[j];

            if (tmpX  >= n or tmpY >= n or tmpX < 0 or tmpY < 0) continue;

            if (mat[ttx][tty] != mat[tmpX][tmpY]) continue;

            if (vis2[tmpX][tmpY] == 1) continue;

            vis2[tmpX][tmpY] = 1;
            sx = tmpX;
            sy = tmpY;
            debug2 (tmpX, tmpY);
            bar = min (bar, (tmpX - r2) * ( tmpX - r2) + (tmpY - c2) * (tmpY - c2));
        }
    }

    return bar;
}

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--; r2--; c1--; c2--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    ans = 0; tx = r2; ty = c2;
    dfs (r1, c1);
    debug1 (ans);

    if (ans) return ! (cout << 0 << endl);

    fill (vis, -1);
    int mn = foo (r1, c2);

    for (int i = 0, sx = r1,  sy = c1; i < (n * n); i++) {
        debug3 (sx, sy, 0);
        vis[sx][sy] = 1;

        for (int j = 0; j < 4; j++) {
            int tmpX = sx + dx[j];
            int tmpY = sy + dy[j];

            if (tmpX  >= n or tmpY >= n or tmpX < 0 or tmpY < 0) continue;

            if (mat[sx][sy] != mat[tmpX][tmpY]) continue;

            if (vis[tmpX][tmpY] == 1) continue;

            vis[tmpX][tmpY] = 1;
            debug2 (tmpX, tmpY);
            sx = tmpX;
            sy = tmpY;
            //mn = min (mn, foo (tmpX, tmpY));
            ckk;
        }
    }

    cout << mn << endl;
    return 0;
}
