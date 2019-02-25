/*
 * FILE: 1118C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1118/problem/C
 *
 * DATE CREATED: 19-02-19 20:47:28 (+06)
 * LAST MODIFIED: 19-02-19 22:41:21 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 19-02-19     1.0         Deleted code is debugged code.
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

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    int n, tmp;
    cin >> n;
    map<int, int> mp;

    for (int i = 0; i < n * n; i++) {
        cin >> tmp;
        mp[tmp]++;
    }

    int four = 0, two = 0, one = 0;
    int max4 = (n / 2) * (n / 2), max2 = (n / 2) * 2;
    queue<int> setFour, setTwo, setOne;

    for (auto i : mp) {
        tmp = i.second;
        int tmp2 = tmp;
        //debug2 (i.first, i.second);
        rep (j, tmp2 / 4) {
            if (four >= max4) break;

            setFour.push (i.first);
            four++;
            tmp -= 4;
        }
        tmp2 = tmp;
        rep (j, tmp2 / 2) {
            if (two >= max2) break;

            setTwo.push (i.first);
            two++;
            tmp -= 2;
        }
        one += tmp;

        if (tmp) {
            setOne.push (i.first);
        }

        //debug3 (four, two, one);
    }

    //debug3 (four, two, one);
    bool flag = false;
    int mat[21][21];
    rep (i, n)rep (j, n) mat[i][j] = -1;

    if (n & 1) {
        if (four == max4 and two == max2 and one == 1) {
            flag = true;

            /// four
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    tmp = setFour.front();
                    setFour.pop();
                    mat[i][j] = tmp;
                    mat[n - 1 - i][j] = tmp;
                    mat[i][n - 1 - j] = tmp;
                    mat[n - 1 - i][n - 1 - j] = tmp;
                }
            }

            /// two
            for (int j = 0; j < n / 2; j++) {
                tmp = setTwo.front();
                setTwo.pop();
                mat[j][n / 2] = tmp;
                mat[n - 1 - j][n / 2] = tmp;
            }

            /// two
            for (int j = 0; j < n / 2; j++) {
                tmp = setTwo.front();
                setTwo.pop();
                mat[n / 2][j] = tmp;
                mat[n / 2][n - 1 - j] = tmp;
            }

            /// one
            mat[n / 2][n / 2] = setOne.front();
        }

    } else {
        if (four * 4 == n * n) {
            flag = true;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == -1) {
                        tmp = setFour.front();
                        setFour.pop();
                        mat[i][j] = tmp;
                        mat[n - 1 - i][j] = tmp;
                        mat[i][n - 1 - j] = tmp;
                        mat[n - 1 - i][n - 1 - j] = tmp;
                    }
                }
            }
        }
    }

    cout << (flag ? "YES\n" : "NO\n");

    for (int i = 0; i < n and flag; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << ' ';
        }

        cout << endl;
    }

    if (flag)
        cout << endl;

    return 0;
}
