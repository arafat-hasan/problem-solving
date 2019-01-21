/*
 * FILE: 1068B.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1068/problem/B
 *
 * DATE CREATED: 24-10-18 23:38:55 (+06)
 * LAST MODIFIED: 25-10-18 00:25:21 (+06)
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-10-18     1.0         Deleted code is debugged code.
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
#define MAXS            10000008 // 1e8+8

////////////////////////// START HERE //////////////////////////

int fact[10000][2]; //for prime factor
int isPrime[MAXS], prime[MAXS];  // Primes class


bool isprime (ll num) {
    if (num == 2) return true;

    if (num < 2 or num % 2 == 0) return false;

    ll i, root = (ll) sqrt (num);

    for (i = 3; i <= root; i += 2)
        if (num % i == 0)    return false;

    return true;
}

int primefactor (long long n, int primesize) {
    int i, j;

    if (n == 0)
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


int main() {
    _FastIO;
    int primesize = sieve (MAXS);
    ll b;
    cin >> b;

    if (b == 1) return ! (cout << "1\n");

    if (b == 2) return ! (cout << "2\n");

    int ans = isprime (b) ? -1 : primefactor (b, primesize);
    cout << ans + 2 << endl;
    return 0;
}
