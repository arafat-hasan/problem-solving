/*
 * FILE: 1156B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1156/problem/B
 *
 * DATE CREATED: 01-05-19 21:11:16 (+06)
 * LAST MODIFIED: 01-05-19 21:17:27 (+06)
 *
 * VERDICT:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 01-05-19     1.0         Deleted code is debugged code.
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
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        map<char, int> mp;

        for (int i = 0; i < (int) str.size(); i++) {
            mp[str[i]]++;
        }

        string ans, ansBak;

        for (int i = 'a'; i <= 'z'; i += 2) {
            for (int j = 0; j < mp[ (char) i]; j++) {
                ans.pb ((char) i);
            }
        }

        ansBak = ans;
        //debug1 (ans);

        for (int i = 'b'; i <= 'z'; i += 2) {
            for (int j = 0; j < mp[ (char) i]; j++) {
                ans.pb ((char) i);
            }
        }

        for (int i = 'z'; i >= 'b'; i -= 2) {
            for (int j = 0; j < mp[ (char) i]; j++) {
                ansBak.pb ((char) i);
            }
        }

        bool flag1 = true, flag2 = true;

        for (int i = 1; i < (int) ans.size(); i++) {
            if (abs (ans[i] - ans[i - 1]) == 1) {
                flag1 = false;
            }

            if (abs (ansBak[i] - ansBak[i - 1]) == 1) {
                flag2 = false;
            }
        }

        debug2 (ans, ansBak);
        debug2 (flag1, flag2);
        ckk;

        if (flag1 and flag2) {
            cout << ans << endl;

        } else if (flag1) {
            cout << ans << endl;

        } else if (flag2) {
            cout << ansBak << endl;

        } else cout << "No Answer" << endl;
    }

    return 0;
}
