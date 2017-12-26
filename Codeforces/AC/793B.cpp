/*
 * FILE: 793B.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://codeforces.com/contest/793/problem/B
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
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

typedef long long ll;
typedef double lf;

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
#define chk cout << "##########\n"

#define LR 2
#define UD 3

using namespace std;

int valid(int tx, int ty);
bool valid2(int tx, int ty, int sx, int sy);
bool isbak(int tx, int ty, int x, int y) ;
void dfs(int sx, int sy, int dx, int dy);
int fx[] = {1, -1, 0, 0}; //DURL
int fy[] = {0, 0, 1, -1};
int bak[1010][1010];
char land[1010][1010]; // for BFS & bfs_vis
int visited [1010][1010]; //for bfs_vis
int n, m;

int main() {

    int sx, sy, dx, dy;
    cin >> n >> m;
    REP(i, n) {
        REP(j, m) {
            cin >> land[i][j];
            if (land[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (land[i][j] == 'T') {
                dx = i;
                dy = j;
            }
        }
    }

    REP(i, n + 1) {
        REP(j, m + 1) {
            bak[i][j] = -INF;
        }
    }
    visited[sx][sy] = 1;
    bak[sx][sy] = 2;
    dfs(sx, sy, dx, dy);
    cout << "NO\n";
    return 0;
}

void dfs(int sx, int sy, int dx, int dy) {
    int i, tx, ty;
    for (i = 0; i < 4; i++) {
        tx = sx + fx[i];
        ty = sy + fy[i];
        if (valid(tx, ty)) {
            if (valid2(tx, ty, sx, sy)) {
                if (isbak(tx, ty, sx, sy)) bak[tx][ty] = bak[sx][sy] - 1;
                else bak[tx][ty] = bak[sx][sy];
                sx == tx ? visited[tx][ty] = LR : visited[tx][ty] = UD;//2 = LR, 3 = UD
                if (tx == dx && ty == dy) {
                    cout << "YES\n";
                    exit(0);
                }
                dfs(tx, ty, dx, dy);
            }
        }
    }
}


bool valid2(int tx, int ty, int sx, int sy) {
    if (visited[tx][ty] == 0) {
        if (isbak(tx, ty, sx, sy)) {
            if (bak[sx][sy] >= 1)
                return 1;
            return 0;
        }
        return 1;
    }
    if (isbak(tx, ty, sx, sy)) {
        if (bak[tx][ty] <= bak[sx][sy] - 1) {
            return 1;
        }
        return 0;
    } else {
        if (bak[tx][ty] <= bak[sx][sy] - 1) {
            return 1;
        }
        return 0;
    }
    return 1;

}
int valid(int tx, int ty) {
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && land[tx][ty] != '*')
        return 1;
    return 0;
}

bool isbak(int tx, int ty, int x, int y) {
    if (visited[x][y] == 1) return 0;
    if ((visited[x][y] == LR && tx == x) || (visited[x][y] == UD
            && ty == y)) return 0;
    return 1;
}

