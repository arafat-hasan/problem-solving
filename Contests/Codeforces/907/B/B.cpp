/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-12-17 20:54:30 (+06)
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-12-17     1.0         {{File Created}}
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

char mat[9][9];

void fun (int x_l, int x_h, int y_l, int y_h) {
    bool fl = false;

    for (int i = y_l; i <= y_h; i++) {
        for (int j = x_l; j <= x_h; j++) {
            if (mat[i][j] == '.') {
                fl = true;
                mat[i][j] = '!';
            }
        }
    }

    if (fl == false) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] == '.') mat[i][j] = '!';
            }
        }
    }
}

int main() {
    __FastIO;
    int lastX, lastY;

    for (int i = 0, y = 0; i < 11; i++) {
        if (i == 3 or i == 7) continue;

        for (int j = 0, x = 0; j < 11; j++) {
            if (j == 3 or j == 7) continue;

            cin >> mat[y][x++];
        }

        y++;
    }

    cin >> lastX >> lastY; lastX--; lastY--;
    swap (lastX, lastY);

    if (lastX  == 0 or lastX == 3 or lastX == 6 ) {
        if (lastY == 0 or lastY == 3 or lastY == 6) {
            fun (0, 2, 0, 2); // upper-left
        } else if ( lastY == 1 or lastY == 4 or lastY == 7 ) {
            fun (0, 2, 3, 5); // middele-left
        } else {
            fun (0, 2, 6, 8); // bottom-left
        }
    } else if (lastX == 1 or lastX == 4 or lastX == 7) {
        if (lastY == 0 or lastY == 3 or lastY == 6) {
            fun (3, 5, 0, 2); // upper-middle
        } else if ( lastY == 1 or lastY == 4 or lastY == 7 ) {
            fun (3, 5, 3, 5); // middele-middle
        } else {
            fun (3, 5, 6, 8); // bottom-middle
        }
    } else {
        if (lastY == 0 or lastY == 3 or lastY == 6) {
            fun (6, 8, 0, 2); // upper-right
        } else if ( lastY == 1 or lastY == 4 or lastY == 7 ) {
            fun (6, 8, 3, 5); // middele-right
        } else {
            fun (6, 8, 6, 8); // bottom-right
        }
    }

    for (int i = 0, y = 0; i < 11; i++) {
        if (i == 3 or i == 7) {
            cout << endl;
            continue;
        }

        for (int j = 0, x = 0; j < 11; j++) {
            if (j == 3 or j == 7) {
                cout << ' ';
                continue;
            }

            cout <<  mat[y][x++];
        }

        cout << endl;
        y++;
    }

    cout << endl;
    return 0;
}


