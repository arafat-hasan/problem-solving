/*
 * FILE: The_One-Handed_Typist-10393.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-07-17 01:11:08 (+06)
 * LAST MODIFIED: 24-07-17 03:48:54 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-07-17     1.0         File Created, Accepted
 *
 */


/*
//     ___          ___           ___                       ___
//    /  /\        /  /\         /__/\        ___          /__/\
//   /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
//  /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
//  \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
//     \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
//      \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
//      /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
//     /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
//     \__\/      \  \::/       \  \:\         \__\/      \  \:\
//                 \__\/         \__\/                     \__\/
*/

/////////////////////////////////////////////////////////////////////////////

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

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cout << #x << ": " << x << endl
#define debug2(x, y)    cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-10
#define MAX             10000005

////////////////////////// START HERE //////////////////////////


int main() {
    __FastIO;
    int f, n, len, cnt, tmp, max;
    string str;
    map<char, int> mp;

    mp['q'] = 1; mp['a'] = 1; mp['z'] = 1;
    mp['w'] = 2; mp['s'] = 2; mp['x'] = 2;
    mp['e'] = 3; mp['d'] = 3; mp['c'] = 3;
    mp['r'] = 4; mp['f'] = 4; mp['v'] = 4; mp['t'] = 4; mp['g'] = 4;
    mp['b'] = 4;
    //Special Case : ' ' -- > 5, 6
    mp['y'] = 7; mp['h'] = 7; mp['n'] = 7; mp['u'] = 7; mp['j'] = 7;
    mp['m'] = 7;
    mp['i'] = 8; mp['k'] = 8; mp[','] = 8;
    mp['o'] = 9; mp['l'] = 9; mp['.'] = 9;
    mp['p'] = 10; mp[';'] = 10; mp['/'] = 10;

    while (cin >> f >> n) {
        set<int> forbidden;
        vector<string> ans;
        set<string> foo;
        Rep(i, f) {
            cin >> tmp;
            forbidden.insert(tmp);
        }

        Rep(i, n) {
            cin >> str;
            len = (int) str.size();
            cnt = 0;
            Rep(j, len) {
                if (forbidden.count(mp[str[j]]) == 0) cnt++;
            }
            if (cnt == len) {
                ans.pb(str);
            }
        }

        len = (int) ans.size();
        max = -INF;
        cnt = 0;
        Rep(i, len) {
            tmp = (int) ans[i].size();
            if (tmp > max) {
                cnt = 1;
                max = tmp;
                foo.clear();
                foo.insert(ans[i]);
            } else if ( max == tmp) {
                cnt++;
                foo.insert(ans[i]);
            }
        }
        cout << foo.size() << '\n';
        Rep(i, len) if ((int) ans[i].size() == max and foo.count(ans[i]) != 0) {
            cout << ans[i] << '\n';
            foo.erase(ans[i]);
        }
    }
    return 0;
}

