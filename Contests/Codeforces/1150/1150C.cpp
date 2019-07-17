/*
 * FILE: 1150C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/1150/problem/C
 *
 * DATE CREATED: 29-04-19 21:41:02 (+06)
 * LAST MODIFIED: 29-04-19 22:19:47 (+06)
 *
 * VERDICT: Almost Accepted
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 29-04-19     1.0         Deleted code is debugged code.
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
#include <iterator> // std::istream_iterator
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

bool isPrime[MAXS]; //for sieve

void sieve (int n) {
    int i, j;
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
}

int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    int n;
    sieve (MAXS);
    cin >> n;
    int twos = 0, ones = 0;
    int sum = 0;
    rep (i, n) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        ones += tmp == 1;
        twos += tmp == 2;
    }
    vi primes;

    for (int i = 0; i <= sum; i++) {
        if (isPrime[i] == 0) {
            primes.pb (i);
        }
    }

    vi ans;
    int curr = 0, nxt = 0;

    for (int i = 0; i < (int) primes.size(); i++) {
        nxt = primes[i];

        while (true) {
            if (twos == 0 or nxt - curr == 1 or nxt == curr) break;

            curr += 2;
            ans.pb (2);
            twos--;
        }

        while (true) {
            if (ones == 0 or nxt == curr) break;

            curr++;
            ans.pb (1);
            ones--;
        }
    }

    for (int i = 0; i < twos; i++) {
        ans.pb (2);
    }

    for (int i = 0; i < ones; i++) {
        ans.pb (1);
    }

    rep (i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
