/*
 * FILE: 5110-Square-Free_Numbers.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://icpcarchive.ecs.baylor.edu/external/51/5110.pdf
 *
 * DATE CREATED: 06-11-17 18:29:51 (+06)
 * LAST MODIFIED: 07-11-17 22:31:50 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 06-11-17     1.0         {{File Created}}
 *
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005
#define MAXS            10000

////////////////////////// START HERE //////////////////////////

bool primelst[MAXS]; //for sieve
int prime[MAXS]; //for sieve
int fact[100][2]; //for prime factor
//100 will be replaced with max number of factors

int sieve(int n) {

    int i, res, j;
    double root = sqrt(n);
    primelst[0] = primelst[1] = 1;

    for (i = 4; i < n; i += 2)
        primelst[i] = 1;

    for (i = 3, j = 0; i <= root; i += 2) {
        if (!primelst[i]) {
            for (j = i * i; j < n; j += 2 * i)
                primelst[j] = 1;
        }
    }

    for (i = 0, res = 0; i < n; i++) {
        if (primelst[i] == 0) {
            prime[res++] = i;
        }
    }

    return (res - 1);

}


bool isprime(int num) {
    int i, root = (int) sqrt(num);
    if (num < 2)             return false;
    if (num == 2)            return true;
    if (num % 2 == 0)        return false;

    for (i = 3; i <= root; i += 2)
        if (num % i == 0)    return false;

    return true;
}

int primefactor(int n, int primesize) {
    // res is return value of seive
    int i, j;

    if (n == 0 || isprime(n) == 1)
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
    int primesz = sieve(MAXS);
    int tc, n, maxx, j;
    cin >> tc;
    while (tc--) {
        cin >> n;
        j = primefactor(n, primesz);
        maxx = -INF;
        for (int i = 0; i < j; i++) {
            maxx = max(maxx, fact[i][1]);
        }
        cout << (maxx == -INF ? 1 : maxx) << '\n';
    }
    return 0;
}

