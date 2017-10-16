/*
 * FILE: Dungeon_Master-532.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    09 Apr 2017    New             1.0
 *
 */


/*
    ___          ___           ___                       ___
   /  /\        /  /\         /__/\        ___          /__/\
  /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
 /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
 \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
    \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
     \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
     /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
    /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
    \__\/      \  \::/       \  \:\         \__\/      \  \:\
                \__\/         \__\/                     \__\/
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <set>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646


/*****************____________BIT_OPERATIONS____________****************/
// #define bit(n) (1 << (n)) //2^n
// //check ith bit of integer n, 0 or 1
// #define bitchk(n, i) ((n & (1 << i))? 1 : 0)
// #define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
// #define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
// //toggle ith bit of integer n, set 0 if 1, set 1 if 0
// #define bit_toggle(n, i) (n ^ ( 1 << i))
// //set ith bit to x (x is bool, 1 or 0) of the integer n
// #define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define ln cout << '\n';
#define sp cout << ' ';
#define chk cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"

typedef long long ll;
typedef double lf;
using namespace std;

char grid[31][31][31], vis[31][31][31];
int cost[31][31][31];
int fx[] = {1, 0, -1, 0, 0, 0}; //R>F>L>B>U>D
int fy[] = {0, -1, 0, 1, 0, 0};
int fz[] = {0, 0, 0, 0, 1, -1};
int l, c, r, sx, sy, sz, ex, ey, ez;

bool isvalid(int tx, int ty, int tz) {
    if ((grid[tz][ty][tx] == '#') || (tx >= c || tx < 0) || (tz >= l || tz < 0)
            || (ty >= r || ty < 0) || (vis[tz][ty][tx] == 1)) {
        return false;
    }

    return true;
}
int bfs3D() {
    if (sx == ex && sy == ey && sz == ez) return 0;
    int i, j, k, tx, ty, tz, ux, uy, uz;
    for (i = 0; i < 31; i++) {
        for (j = 0; j < 31; j++) {
            for (k = 0; k < 31; k++) {
                cost[i][j][k] = -1;
                vis[i][j][k] = 0;
            }
        }
    }

    queue<int> Qx;
    queue<int> Qy;
    queue<int> Qz;
    Qx.push(sx);
    Qy.push(sy);
    Qz.push(sz);
    cost[sz][sy][sx] = 0;

    while (!Qx.empty()) {
        ux = Qx.front();
        uy = Qy.front();
        uz = Qz.front();
        Qx.pop();
        Qy.pop();
        Qz.pop();

        for (i = 0; i < 6; i++) {
            tx = ux + fx[i];
            ty = uy + fy[i];
            tz = uz + fz[i];

            if (isvalid(tx, ty, tz)) {
                Qx.push(tx);
                Qy.push(ty);
                Qz.push(tz);
                cost[tz][ty][tx] = cost[uz][uy][ux] + 1;
                vis[tz][ty][tx] = 1;
                if (tx == ex && ty == ey && tz == ez) return cost[tz][ty][tx];
            }
        }
    }
    return INF;
}



int main() {

    std::ios::sync_with_stdio(false);
    int i, j, k, ans;
    while (cin >> l >> r >> c && (l || r || c)) {

        for (i = 0; i < l; i++) {
            for (j = 0; j < r; j++) {
                for (k = 0; k < c; k++) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') {
                        sx = k; sy = j; sz = i;
                    }
                    if (grid[i][j][k] == 'E') {
                        ex = k; ey = j; ez = i;
                    }
                }
            }
        }

        ans = bfs3D();
        if (ans == INF) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";

    }

    return 0;
}


