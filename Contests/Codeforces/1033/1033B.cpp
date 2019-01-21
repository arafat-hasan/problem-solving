/*
 * FILE: 1033B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1033/problem/B
 *
 * DATE CREATED: 07-10-18 23:19:11 (+06)
 * LAST MODIFIED: 07-10-18 23:31:53 (+06)
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 07-10-18     1.0         Deleted code is debugged code.
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
#define MAXS            10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

int segsieve[100000];
bool isPrime[MAXS]; //for sieve
int prime[MAXS]; //for sieve

int sieve (int n) {
    int i, res, j;
    double root = sqrt (n);
    isPrime[0] = isPrime[1] = 1;

    for (i = 4; i < n; i += 2)
        isPrime[i] = 1;

    for (i = 3, j = 0; i <= root; i += 2) {
        if (!isPrime[i]) {
            for (j = i * i; j < n; j += 2 * i)
                isPrime[j] = 1;
        }
    }

    for (i = 0, res = 0; i < n; i++) {
        if (isPrime[i] == 0) {
            prime[res++] = i;
        }
    }

    return (res - 1);
}




///Returns number of primes between segment [a,b]
int segmentedSieve ( ll a, ll b, int primesize) {
    if ( a == 1 ) a++;

    ll sqrtn = (ll) sqrt (b);
    memset ( segsieve, 0, sizeof segsieve ); ///Make all index of segsieve 0.

    // maxprime is used in bit sieve or normal seive code
    for ( ll i = 0; i < primesize && prime[i] <= sqrtn; i++ ) {
        ll p = prime[i];
        ll j = p * p;

        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

        for ( ; j <= b; j += p ) {
            segsieve[j - a] = 1; ///mark them as not prime
        }
    }

    int res = 0;

    for ( ll i = a; i <= b; i++ ) {
        ///If it is not marked, then it is a prime
        if ( segsieve[i - a] == 0 ) res++;
    }

    return res;
}

int main() {
    _FastIO;
    ll t, a, b;
    int primesize = sieve (MAXS);
    cin >> t;

    while (t--) {
        cin >> a >> b;
        bool ans = false;

        if (a - b == 1) {
            ll num = a + b;
            int res = segmentedSieve (num, num, primesize);
            ans = res == 1 ? true : false;

        } else {
            ans = false;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
