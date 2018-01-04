/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29-12-17 22:06:30 (+06)
 * LAST MODIFIED: 29-12-17 22:28:34 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 29-12-17     1.0         {{File Created}}
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

string str;
char mat[100][100];
int n, m, cnt = 0;
int sx, sy;

bool solve (map<int, char> mp) {
    int x = sx, y = sy;

    for (auto i : str) {
        int tmp = i - '0';

        if (mp[tmp] == 'u') y--;
        else if (mp[tmp] == 'd') y++;
        else if (mp[tmp] == 'l') x++;
        else if (mp[tmp] == 'r') x--;

        if ( (x < 0 or x >= m) or (y < 0 or y >= n) )
            return false;

        if (mat[y][x] == 'E') return true;

        if (mat[y][x] == '#') return false;
    }

    return false;
}


int main() {
    __FastIO;
    cin >> n >> m;
    rep (i, n) rep (j, m) {
        cin >> mat[i][j];

        if (mat[i][j] == 'S') {
            sx = j; sy = i;
        }
    }
    cin >> str;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;

            for (int k = 0; k < 4; k++) {
                if (k == j or k == i) continue;

                for (int l = 0; l < 4; l++) {
                    if (l == k or l == j or l == i) continue;

                    map<int, char> mp ({{i, 'u'}, {j, 'd'}, {k, 'l'}, {l, 'r'}});

                    if (solve (mp) == true) {
                        cnt++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}


