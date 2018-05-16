/*
 * FILE: 979B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 14-05-18 21:00:00 (+06)
 * LAST MODIFIED: 14-05-18 22:14:31 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 14-05-18     1.0         File Created, Accepted
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

#define _USE_MATH_DEFINES

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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
    #define debug1(x)       cerr << #x << ": " << (x) << endl
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << endl
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << endl
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
    __FastIO;
    int n;
    int b_sh = -INF, b_ku = -INF, b_ka = -INF;
    string shiro, kuro, katie;
    map<char, int> sh, ku, ka;
    cin >> n >> kuro >> shiro >> katie;
    //debug1 (n);
    //debug1 (kuro);
    //debug1 (shiro);
    //debug1 (katie);
    //ckk;
    int sz = (int) kuro.size();

    for (int i = 0; i < (int) kuro.size(); i++) {
        ku[kuro[i]]++;
    }

    for (int i = 0; i < (int) shiro.size(); i++) {
        sh[shiro[i]]++;
    }

    for (int i = 0; i < (int) katie.size(); i++) {
        ka[katie[i]]++;
    }

    for (auto i : ku) b_ku = max (i.second, b_ku);

    for (auto i : sh) b_sh = max (i.second, b_sh);

    for (auto i : ka) b_ka = max (i.second, b_ka);

    //debug3 (b_ku, b_sh, b_ka);
    /// ugly
    int u_sh = sz - b_sh;
    int u_ku = sz - b_ku;
    int u_ka = sz - b_ka;
    //debug3 (u_ka, u_sh, u_ka);
    /// extra n's
    int baki_sh = n - u_sh;
    int baki_ka = n - u_ka;
    int baki_ku = n - u_ku;
    //debug3 (baki_ku, baki_sh, baki_ka);

    if (baki_sh > 0) {
        b_sh = baki_sh & 1 ?  sz - 1 : sz;

    } else {
        b_sh = b_sh + n;
    }

    if (baki_ka > 0) {
        b_ka = baki_ka & 1 ? sz - 1 : sz;

    } else {
        b_ka = b_ka + n;
    }

    if (baki_ku > 0) {
        b_ku = baki_ku & 1 ?  sz - 1 : sz;

    } else {
        b_ku = b_ku + n;
    }

    debug3 (b_ku, b_sh, b_ka);

    if (b_ku > b_sh and b_ku > b_ka) {
        cout << "Kuro\n";

    } else if (b_ka > b_sh and b_ka > b_ku) {
        cout << "Katie\n";

    } else if (b_sh > b_ka and b_sh > b_ku) {
        cout << "Shiro\n";

    } else {
        cout << "Draw\n";
    }

    return 0;
}

