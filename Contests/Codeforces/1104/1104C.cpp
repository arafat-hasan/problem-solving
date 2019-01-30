/*
 * FILE: 1104C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1104/problem/C
 *
 * DATE CREATED: 22-01-19 22:05:15 (+06)
 * LAST MODIFIED: 22-01-19 22:23:42 (+06)
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 22-01-19     1.0         Deleted code is debugged code.
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

////////////////////////// START HERE //////////////////////////

int mat[4][4];

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    string str;
    cin >> str;

    for (size_t i = 0; i < str.size(); i++) {
        int r = 0, c = 0;

        if (str[i] == '0') {
            for (int j = 0; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    if (mat[k][j] == 0 and mat[k - 1][j] == 0) {
                        c = j;
                        r = k - 1;
                        mat[k][j] = 1;
                        mat[k - 1][j] = 1;
                        bool flag = true;

                        for (int l = 0; l < 4; l++) {
                            if (mat[l][j] == 0) {
                                flag = false;
                                break;
                            }
                        }

                        if (flag) {
                            for (int l = 0; l < 4; l++) {
                                mat[l][j] = 0;
                            }
                        }
                        break;
                    }
                }
            }

        } else {
            for (int j = 0; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    if (mat[j][k] == 0 and mat[j][k - 1] == 0) {
                        r = j;
                        c = k - 1;
                        mat[j][k] = 1; mat[j][k - 1] = 1;
                        bool flag = true;

                        for (int l = 0; l < 4; l++) {
                            if (mat[j][l] == 0) {
                                flag = false;
                                break;
                            }
                        }

                        if (flag) {
                            for (int l = 0; l < 4; l++) {
                                mat[j][l] = 0;
                            }
                        }
                        break;
                    }
                }
            }
        }

        cout << r + 1 << ' ' << c + 1 << '\n';
    }

    return 0;
}
