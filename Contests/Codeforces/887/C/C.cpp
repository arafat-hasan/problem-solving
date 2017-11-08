/*
 * FILE: C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03-11-17 23:50:34 (+06)
 * LAST MODIFIED: 04-11-17 01:27:51 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 03-11-17     1.0         {{File Created}}
 *
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

int main() {
    __FastIO;
    int mat[2][8];
    int tam[2][8];
    int arr[24];
    rep(i, 24) cin >> arr[i];

    mat[0][0] = arr[1 - 1];
    mat[0][1] = arr[3 - 1];
    mat[0][2] = arr[5 - 1];
    mat[0][3] = arr[7 - 1];
    mat[0][4] = arr[9 - 1];
    mat[0][5] = arr[11 - 1];
    mat[0][6] = arr[24 - 1];
    mat[0][7] = arr[22 - 1];

    mat[1][0] = arr[2 - 1];
    mat[1][1] = arr[4 - 1];
    mat[1][2] = arr[6 - 1];
    mat[1][3] = arr[8 - 1];
    mat[1][4] = arr[10 - 1];
    mat[1][5] = arr[12 - 1];
    mat[1][6] = arr[23 - 1];
    mat[1][7] = arr[21 - 1];

    tam[0][0] = arr[13 - 1];
    tam[0][1] = arr[14 - 1];
    tam[0][2] = arr[5 - 1];
    tam[0][3] = arr[6 - 1];
    tam[0][4] = arr[17 - 1];
    tam[0][5] = arr[18 - 1];
    tam[0][6] = arr[21 - 1];
    tam[0][7] = arr[22 - 1];

    tam[1][0] = arr[15 - 1];
    tam[1][1] = arr[16 - 1];
    tam[1][2] = arr[7 - 1];
    tam[1][3] = arr[8 - 1];
    tam[1][4] = arr[19 - 1];
    tam[1][5] = arr[20 - 1];
    tam[1][6] = arr[23 - 1];
    tam[1][7] = arr[24 - 1];


    rep(i, 8) debug2(mat[0][i], mat[1][i]);
    nl;
    rep(i, 8) debug2(tam[0][i], tam[1][i]);
    ckk;

    bool fl = true;
    rep(i, 8) if (mat[0][i] != mat[1][i]) {
        fl = false;
        break;
    }

    if (fl != false) {
        rep(i, 8) {
            if (tam[0][i] != tam[1][i]) {
                fl = false;
            }
        }
        if (fl == true) return !(cout << "YES\n");
    }

    fl = true;
    for (int i = 0, j = 2; i < 8; i++, j = (j + 1) % 8) {
        //debug2(i, j);
        if (mat[0][i] != mat[1][j]) {
            fl = false;
            break;
        }
    }
    //debug1(fl);

    if (fl) {
        if (tam[0][1] == tam[0][0] and tam[0][0] == tam[1][0] and \
                tam[1][0] == tam[1][1] and \
                tam[0][4] == tam[0][5] and tam[0][5] == tam[1][4] and \
                tam[1][4] == tam[1][5]) {
            return !(cout << "YES\n");
        }
    }

    fl = true;
    for (int i = 2, j = 0; j < 8; j++, i = (i + 1) % 8) {
        if ( mat[0][i] != mat[1][j]) {
            fl = false;
            break;
        }
    }

    if (fl) {
        if (tam[0][1] == tam[0][0] and tam[0][0] == tam[1][0] and \
                tam[1][0] == tam[1][1] and \
                tam[0][4] == tam[0][5] and tam[0][5] == tam[1][4] and \
                tam[1][4] == tam[1][5]) {
            return !(cout << "YES\n");
        }
    }


    fl = true;
    for (int i = 0, j = 2; i < 8; i++, j = (j + 1) % 8) {
        if (tam[0][i] != tam[1][j]) {
            fl = false;
            break;
        }
    }

    if (fl) {
        if (mat[0][0] == mat[0][1] and mat[0][0] == mat[1][0] \
                and mat[0][0] == mat[1][1] and \
                mat[0][4] == mat[1][4] and mat[0][4] == mat[0][5] \
                and mat[0][4] == mat[1][5]) {
            return !(cout << "YES\n");
        }
    }

    fl = true;
    for (int i = 2, j = 0; j < 8; j++, i = (i + 1) % 8) {
        if ( tam[0][i] != tam[1][j]) {
            fl = false;
            break;
        }
    }

    if (fl) {
        if (mat[0][0] == mat[0][1] and mat[0][0] == mat[1][0] \
                and mat[0][0] == mat[1][1] and \
                mat[0][4] == mat[1][4] and mat[0][4] == mat[0][5] \
                and mat[0][4] == mat[1][5]) {
            return !(cout << "YES\n");
        }
    }

    cout << "NO\n";
    return 0;
}

