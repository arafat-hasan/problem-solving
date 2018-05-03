/*
 * FILE: GCDDIV.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://www.codechef.com/LTIME59B/problems/GCDDIV
 *
 * DATE CREATED: 28-04-18 21:00:44 (+06)
 * LAST MODIFIED: 28-04-18 21:52:36 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 28-04-18     1.0         {{File Created}}
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


#define                 _USE_MATH_DEFINES
#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = a; i <= b; i++)
#define rof(i, b, a)    for (__typeof (a) i = b; i >= a; i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < n; i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(ar)          memset(ar, 0, sizeof(ar))

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
#define MAXS            31700

////////////////////////// START HERE //////////////////////////


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

int main() {
    __FastIO;
    int t, n, k;
    int prime_sz = sieve (MAXS);
    cin >> t;

    while (t--) {
        cin >> n >> k;
        vi v (n);
        rep (i, n) cin >> v[i];
        int index = prime_sz;

        if (k < prime[prime_sz]) {
            for (int i = 0; i <= prime_sz; i++) {
                if (prime[i] > k) {
                    index = i - 1;
                    break;
                }
            }
        }

        for (int i = index; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (v[j] % prime[i] == 0) v[j] /= prime[i];
            }
        }

        bool ans = true;

        for (int i = index + 1; i <= prime_sz; i++) {
            bool flag = true;

            for (int j = 0; j < n; j++) {
                if (v[j] % prime[i] != 0) {
                    flag = false;
                }
            }

            if (flag) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}

