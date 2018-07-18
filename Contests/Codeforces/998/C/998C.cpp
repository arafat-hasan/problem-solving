/*
 * FILE: 998C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01-07-18 21:31:12 (+06)
 * LAST MODIFIED: 01-07-18 22:20:12 (+06)
 *
 * VERDICT:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 01-07-18     1.0         Deleted code is debugged code.
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

#define _FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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


int n, x, y;
string str;
int foo() {
    auto it = unique (str.begin(), str.end() );
    str.resize (distance (str.begin(), it) );
    return (int) std::count (str.begin(), str.end(), '0');
}

int main() {
    _FastIO;
    cin >> n >> x >> y >> str;

    if (y <= x) {
        ll tmp = (ll) foo();
        cout << (tmp * y) << endl;

    } else {
        ll ans = 0;
        str.pb ('0');

        while (true) {
            bool flag = false, here = false;
            int start = 0, one_cnt = 0;

            for (int i = 0; i < n + 1; i++) {
                if (flag) {
                    if (str[i] == '1' and str[i + 1] == '0') {
                        reverse (str.begin() + start, str.begin() + i + 1);
                        start += one_cnt + 1;
                        here = true;
                        ans += x;

                    } else if (str[i] == '1') {
                        one_cnt++;
                    }

                } else {
                    if (str[i] == '1' and str[i + 1] == '0') {
                        start = i + 1;
                        flag = true;
                    }
                }
            }

            if (here == false) {
                for (int i = n - 1; i >= 0; i--) {
                    if (str[i] == '1') {
                        if (i == n - 1) {
                            ans = -y;
                            break;
                        }

                        reverse (str.begin(), str.begin() + i + 1);
                        ans += x;
                        break;
                    }
                }

                break;
            }
        }

        ans += y;
        cout << ans << endl;
    }

    return 0;
}
