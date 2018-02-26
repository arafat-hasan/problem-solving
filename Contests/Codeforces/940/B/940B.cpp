/*
 * FILE: 940B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-02-18 16:01:02 (+06)
 * LAST MODIFIED: 24-02-18 16:54:06 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-02-18     1.0         {{File Created}}
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

ll k, a, b;

ll fun (ll sum, ll n) {
    if (k == 1) {
        return  (n - 1) * a;
    }

    if (n < k) {
        sum += ( (n - 1) * a);
        return sum;
    }

    if (n % k != 0 and n > k) {
        sum += ( (n % k) * a);
        n -= (n % k);
    }

    if ( (n - (n / k) ) * a > b and n % k == 0) {
        sum += b;
        n /= k;
    } else if ( (n - (n / k) ) * a < b) {
        sum += ( (n - 1) * a);
        return sum;
    } else {
        sum += a;
        n--;
    }

    return fun (sum, n);
}

int main() {
    __FastIO;
    ll n;
    cin >> n >> k >> a >> b;
    cout << fun (n, 0) << endl;
    return 0;
}


//int main() {
//    __FastIO;
//    ll n, k, a, b, sum = 0;
//    cin >> n >> k >> a >> b;

//    if (k == 1) {
//        return ! (cout << (n - 1) * a);
//    }

//    while (n != 1) {
//        if (n < k) {
//            sum += ( (n - 1) * a);
//            break;
//        }

//        if (n % k != 0 and n > k) {
//            sum += ( (n % k) * a);
//            n -= (n % k);
//        }

//        if ( (n - (n / k) ) * a > b and n % k == 0) {
//            sum += b;
//            n /= k;
//        } else if ( (n - (n / k) ) * a < b) {
//            sum += ( (n - 1) * a);
//            break;
//        } else {
//            sum += a;
//            n--;
//        }
//    }

//    cout << sum << endl;
//    return 0;
//}
