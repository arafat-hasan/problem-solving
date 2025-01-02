/*
 * FILE: 1181B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 17-07-19 18:54:01 (+06)
 * LAST MODIFIED: 17-07-19 18:54:05 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 17-07-19     1.0         Deleted code is debugged code.
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
#include <iterator> // std::istream_iterator
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
    int n;
    string str;
    cin >> n >> str;
    ll numOne = 0, numTwo = 0;
    int midF = n / 2;
    int midS;

    while (str[midF] != '0') {
        midF--;
    }

    while (str[midS] != '0') {
        midS++;
    }

    if (n & 1) {
        debug2 (mid, str[mid]);

        if (str[mid] > str[0]) {
            for (int i = mid, m = 1; i >= 0; --i, m *= 10) {
                numOne += (str[i] - '0') * m;
            }

            for (int i = n - 1, m = 1; i > mid; --i, m *= 10) {
                numTwo += (str[i] - '0') * m;
            }

            debug2 (numOne, numTwo);

        } else {
            for (int i = mid - 1, m = 1; i >= 0; --i, m *= 10) {
                numOne += (str[i] - '0') * m;
            }

            for (int i = n - 1, m = 1; i >= mid; --i, m *= 10) {
                numTwo += (str[i] - '0') * m;
            }

            debug2 (numOne, numTwo);
        }

    } else {
        for (int i = mid - 1, m = 1; i >= 0; --i, m *= 10) {
            numOne += (str[i] - '0') * m;
        }

        for (int i = n - 1, m = 1; i >= mid; --i, m *= 10) {
            numTwo += (str[i] - '0') * m;
        }

        debug2 (numOne, numTwo);
    }

    cout << numOne + numTwo << endl;
    return 0;
}
