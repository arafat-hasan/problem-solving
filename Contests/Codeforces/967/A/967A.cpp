/*
 * FILE: 967A.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 29-04-18 19:33:27 (+06)
 * LAST MODIFIED: 30-04-18 18:28:19 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 29-04-18     1.0         File Created, Accepted
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


int main() {
    __FastIO;
    int n, s, h, m;
    vi v;
    cin >> n >> s;

    while (n--) {
        cin >> h >> m;
        v.push_back (h * 60 + m);
    }

    vi ans;

    if (v[0] - s - 1 >= 0) ans.push_back (0);
    else {
        for (int i = 1; i < (int) v.size(); i++) {
            if (v[i] - (v[i - 1] + 1) >= (s * 2 + 1) ) {
                ans.push_back (v[i - 1] + s + 1);
                break;
            }
        }
    }

    if ( (int) ans.size() == 0) {
        ans.push_back (v[ (int) v.size() - 1] + s + 1);
    }

    sort (all (ans) );
    cout << ans[0] / 60 << ' ' << ans[0] % 60 << endl;
    return 0;
}


