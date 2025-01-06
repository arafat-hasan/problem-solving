/*
 * FILE: Again_Prime_No_Time-10780.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06-03-18 16:41:24 (+06)
 * LAST MODIFIED: 06-03-18 16:58:17 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 28 Jan 2017  1.0         {{File Created}}
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
#define MAXS            100005 //1e5+5

////////////////////////// START HERE //////////////////////////

bool isPrime[MAXS]; //for sieve
int prime[MAXS]; //for sieve
int fact[100][2]; //for prime factor
vpii utpapdok[10005];
//int isPrime[MAXS], prime[MAXS];  // Primes class
//100 will be replaced with max number of factors

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

int primefactor (int n, int primesize) {
    // res is return value of seive
    int i, j;

    if (n == 0 || isPrime[n] == 0)
        return 0;

    for (i = 0, j = 0; i < primesize; i++) {
        if (n % prime[i] == 0) {
            fact[j][0] = prime[i];
            fact[j][1] = 0;

            while (n % prime[i] == 0) {
                n /= prime[i];
                fact[j][1]++;
            }

            j++;
        }
    }

    return j;
}
int main() {
    __FastIO;
    int t, n, m, cs = 0;
    int prime_sz = sieve (10005);

    for (int i = 1; i < 10005; i++) {
        int sz = primefactor (i, prime_sz);

        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < fact[j][1]; k++)
                utpapdok[i].pb (fact[j][0]);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (auto j : utpapdok[i]) debug2 (i, j);

        ckk;
    }

    //cin >> t;
    //while (t--) {
    //    cin >> m >> n;
    //    int sz = primefactor (m, prime_sz);
    //    //fact[][];
    //    int foo[sz][2];
    //    for (int i = 0; i < sz; i++) foo[i][1] = 0, foo[i][0] = fact[i][0];
    //    for (int i = 1; i <= n; i++) {
    //        for (int j = 0; j < sz (utpapdok[i]); j++) {
    //            for (int k = 0; k < sz; k++) {
    //                if (fact[k][0] == utpapdok[i][j]) {
    //                    foo[k][1]++;
    //                }
    //            }
    //        }
    //    }
    //    for (int i = 0; i < sz; i++) {
    //        debug2 (foo[i][0], foo[i][1]);
    //    }
    //}
    return 0;
}

