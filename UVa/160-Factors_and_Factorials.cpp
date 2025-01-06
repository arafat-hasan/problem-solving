/*
 * FILE: Factors_and_Factorials-160.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 26-07-17 17:22:39 (BST)
 * LAST MODIFIED: 26-07-17 22:04:53 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 26-07-17     1.0         File Created, Accepted
 *
 */


/*
//     ___          ___           ___                       ___
//    /  /\        /  /\         /__/\        ___          /__/\
//   /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
//  /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
//  \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
//     \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
//      \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
//      /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
//     /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
//     \__\/      \  \::/       \  \:\         \__\/      \  \:\
//                 \__\/         \__\/                     \__\/
*/

/////////////////////////////////////////////////////////////////////////////

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

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cout << #x << ": " << x << endl
#define debug2(x, y)    cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

// 2^n
#define bit(n)              (1 << (n))
// Check ith bit of integer n, 0 or 1
#define bitchk(n, i)        ((n & (1 << (i)))? 1 : 0)
//set ith bit ON of the integer n
#define bit_on(n, i)        n = (n | (1 << (i)))
//set ith bit OFF of the intger n
#define bit_off(n, i)       n = (n & ~(1 << (i)))
// Toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i)    n = (n ^ ( 1 << (i)))
// Set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i)   n = (n ^ ((-(x) ^ n) & (1 << (i))))

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-10
#define MAX             10000005
#define MAXS            400

////////////////////////// START HERE //////////////////////////



// bitwise seive
int primelst[MAXS / 32]; //for sieve
int prime[MAXS], maxprime; //for sieve

void bit_sieve(int n) {

    int i, j;
    double root = sqrt(n);
    bit_on(primelst[0], 0);
    bit_on(primelst[0], 1);

    for (i = 4; i < n; i += 2)
        bit_on(primelst[i >> 5], i & 31);

    for (i = 3, j = 0; i <= root; i += 2) {
        if (bitchk(primelst[i >> 5], i & 31) == 0) {
            for (j = i * i; j < n; j += 2 * i)
                bit_on(primelst[j >> 5], j & 31);
        }
    }

    for (i = 0, j = 0; i < n; i++) {
        if (bitchk(primelst[i >> 5], i & 31) == 0) {
            prime[j++] = i;
        }
    }

    maxprime = j - 1;
}


int fact[100][2]; //for prime factor
//100 will be replaced with max number of factors

int primefactor(int n) {

    int i, j;

    if (n == 0)
        return 0;

    for (i = 0, j = 0; i < maxprime; i++) {
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
    bit_sieve(MAXS);
    vector<vi> v(101, vi(201, 0));

    for (int i = 0; i < 101; i++) {
        int j = primefactor(i);
        for (int k = 0; k < j; k++) {
            int tmp = fact[k][0];
            int cnt = fact[k][1];
            v[i][tmp] = cnt;
        }
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 0; j < 200; j++) {
            v[i][j] += v[i - 1][j];
        }
    }

    vector<vi> ans(101);
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 100; j++) {
            ans[i].pb(v[i][prime[j]]);
        }
    }

    int n;
    while (cin >> n and n) {
        cout << right << setw(3);
        cout << n << "! =";
        int sz = (int) ans[n].size();
        int line = 0;
        for (int i = 0; i < sz; i++) {
            if (ans[n][i] == 0) break;
            if (line++ == 15) cout << "\n      ";
            cout << right << setw(3);
            cout << ans[n][i];
        }
        cout << '\n';
    }
    return 0;
}

