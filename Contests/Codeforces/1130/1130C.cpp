/*
 * FILE: 1130C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-02-19 22:41:43 (+06)
 * LAST MODIFIED: 25-02-19 18:57:30 (+06)
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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; //4 Direction

////////////////////////// START HERE //////////////////////////

char mat[51][51];
int cost[51][51];
int tx, ty, n;

void dfs (int sx, int sy, vpii v) {
    v.pb ({sx, sy});

    if (sx == tx and sy == ty) return;

    for (int i = 0; i < 4; i++) {
        int tmpX = sx + dx[i];
        int tmpY = sy + dy[i];

        if (tmpX >= n or tmpY >= n or tmpX < 0 or tmpY < 0) continue;

        if (mat[tmpX][tmpY] != mat[sx][sy]) continue;

        dfs (tmpX, tmpY, v);
    }
}

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    int r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    rep (i, n) rep (j, n) cin >> mat[i][j];
    vpii sqrsS, sqrsD;
    tx = r2; ty = c2;
    dfs (r1, c1, sqrsS);
    tx = r1; ty = c1;
    dfs (r2, c2, sqrsD);
    debug2 (sqrsS.size(), sqrsD.size());
    return 0;
}
