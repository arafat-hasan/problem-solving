/*
 * FILE: 864C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 18-02-18 16:21:28 (+06)
 * LAST MODIFIED: 22-02-18 23:34:44 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 18-02-18     1.0         File Created, Accepted
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
#define fill(ar, val)   memset((ar), (val), sizeof((ar)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n';
    #define sp              cerr << ' ';
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
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    //debug3 (a, b, f);

    if (b < f or (a - f) > b) return ! (cout << "-1\n");

    int cokkor = (k & 1 ? k - 1 : k) / 2;
    int fuel_now = b, cnt = 0;
    bool first_time = true;
    int prothom2 = 2 * f;
    int ditio2 = 2 * (a - f);
    int last_trip = (k & 1 ? -1 : k / 2 - 1);
    //debug3 (prothom2, ditio2, last_trip);
    //ckk;

    for (int trip = 0; trip < cokkor; trip++, first_time = false) {
        fuel_now -= (first_time ? f : prothom2);
        fuel_now = (fuel_now < ditio2 ? (cnt++, b) : fuel_now);
        //debug3 ("first: ", fuel_now, cnt);
        fuel_now -= ditio2;

        if (fuel_now < 0) return ! (cout << "-1\n");

        if (trip == last_trip) {
            fuel_now = (fuel_now < f ? (cnt++, b) : fuel_now);
        } else {
            fuel_now = (fuel_now < prothom2 ? (cnt++, b) : fuel_now);
        }

        //debug3 ("sec: ", fuel_now, cnt);
        if (fuel_now < 0) return ! (cout << "-1\n");
    }

    if (k & 1) {
        fuel_now -= (first_time ? f : prothom2);
        if (fuel_now < 0) return ! (cout << "-1\n");
        //debug3 ("sec: ", fuel_now, cnt);
        fuel_now -= (fuel_now < (a - f) ? (cnt++, b) : fuel_now);
    }

    cout << cnt << endl;
    return 0;
}

