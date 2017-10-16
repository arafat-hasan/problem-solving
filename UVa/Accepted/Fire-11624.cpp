/*
 * FILE: Fire-11624.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    19 Mar 2017    New             0.0        Not Completed
 *    28 Mar 2017                    1.0        AC
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


/*****************____________BIT_OPERATIONS____________****************/
#define bit(n) (1 << (n)) //2^n
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << i))? 1 : 0)
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) (n ^ ( 1 << i))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define ln puts("")
#define sp cout << " "
#define lck cout << "@@@@@@@@@@@" << endl

int costfire[1010][1010];
int costsrc[1010][1010];
char maze[1010][1010];
int fx[] = {1, 0, -1, 0};
int fy[] = {0, -1, 0, 1};
int r, c;

typedef long long ll;
typedef double lf;
using namespace std;


int bfssrc(pair<int, int> src) {
    int i, j;
    int v1, v2;
    pair<int, int> cn;
    for (i = 0; i <= r; i++)
        for (j = 0; j <= c; j++)
            costsrc[i][j] = INT_MAX;

    queue<pair<int, int>> Q;
    Q.push(make_pair(src.first, src.second));
    costsrc[src.first][src.second] = 0;
    while (!Q.empty()) {
        cn = Q.front();
        Q.pop();
        for (i = 0; i < 4; i++) {
            v1 = cn.first + fx[i];
            v2 = cn.second + fy[i];
            if (v2 >= c || v2 < 0 || v1 >= r || v1 < 0 || maze[v1][v2] == '#') continue;
            if (costsrc[cn.first][cn.second] + 1 < costsrc[v1][v2]) {
                Q.push(make_pair(v1, v2));
                costsrc[v1][v2] = costsrc[cn.first][cn.second] + 1;
            }
        }
    }

    return 0;
}

int bfsfire(pair<int, int> src) {
    int i;
    int v1, v2;
    pair<int, int> cn;

    queue<pair<int, int>> Q;
    Q.push(make_pair(src.first, src.second));
    costfire[src.first][src.second] = 0;
    while (!Q.empty()) {
        cn = Q.front();
        Q.pop();
        for (i = 0; i < 4; i++) {
            v1 = cn.first + fx[i];
            v2 = cn.second + fy[i];
            if (v1 >= r || v1 < 0  || v2 >= c || v2 < 0 || maze[v1][v2] == '#') continue;
            if (costfire[cn.first][cn.second] + 1 < costfire[v1][v2]) {
                Q.push(make_pair(v1, v2));
                costfire[v1][v2] = costfire[cn.first][cn.second] + 1;
            }
        }
    }

    return 0;
}

int main() {

    std::ios::sync_with_stdio(false);
    int T, i, j, min;
    pair<int, int> src, fire;
    cin >> T;

    while (T--) {
        cin >> r >> c;

        for (i = 0; i < r; i++)
            cin >> maze[i];
        for (i = 0; i <= r; i++)
            for (j = 0; j <= c; j++)
                costfire[i][j] = INT_MAX;

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if ( maze[i][j] == 'F') bfsfire(make_pair(i, j));
                if (maze[i][j] == 'J') src = make_pair(i, j);
            }
        }

        bfssrc(src);
        min = INT_MAX;

        for (i = 0; i < c; i++)
            if (costfire[0][i] > costsrc[0][i])
                if (min > costsrc[0][i])
                    min  = costsrc[0][i];
        for (i = 0; i < r; i++)
            if (costfire[i][0] > costsrc[i][0])
                if (min > costsrc[i][0])
                    min  = costsrc[i][0];
        for (i = 0; i < r; i++)
            if (costfire[i][c - 1] > costsrc[i][c - 1])
                if (min > costsrc[i][c - 1])
                    min  = costsrc[i][c - 1];
        for (i = 0; i < c; i++)
            if (costfire[r - 1][i] > costsrc[r - 1][i])
                if (min > costsrc[r - 1][i])
                    min  = costsrc[r - 1][i];

        if (min == INT_MAX) cout << "IMPOSSIBLE\n";
        else cout << min + 1 << endl;

    }

    return 0;
}


