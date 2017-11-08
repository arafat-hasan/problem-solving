/*
 * FILE: PRIME1.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 22-08-17 20:52:33 (BST)
 * LAST MODIFIED: 22-08-17 21:55:26 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 22-08-17     1.0         File Created
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

#define FileIn(file)    freopen("input.txt", "r", stdin)
#define FileOut(file)   freopen("output.txt", "w", stdout)
#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define sfll(a)         scanf("%lld", &a)
#define pfll(a)         printf("%lld", a)
#define sflf(a)         scanf("%lf", &a)
#define pflf(a)         printf("%lf", a)
#define sff(a)          scanf("%f", &a)
#define pff(a)          printf("%f", a)
#define sf(a)           scanf("%d", &a)
#define pf(a)           printf("%d", a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cout << #x << ": " << x << endl
#define debug2(x, y)    cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

//////////////// BIT SET //////////////

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

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAXN            32001
#define MAXS            10000000
#define MAX             1000000000

////////////////////////// START HERE //////////////////////////

////////////////////////// SIEVE //////////////////////////

bool primelst[MAXS]; //for sieve
int prime[MAXS]; //for sieve

int sieve(int n) {

    clr(primelst);
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

// Segmented Sieve of Eratosthenes

int segsieve[100002];

///Returns number of primes between segment [a,b]
int segmentedSieve ( ll a, ll b, int primesize) {
    if ( a == 1 ) a++;

    int sqrtn = (int) sqrt(b);

    memset ( segsieve, 0, sizeof segsieve ); ///Make all index of segsieve 0.
    // maxprime is used in bit sieve or normal seive code
    for ( int i = 0; i < primesize && prime[i] <= sqrtn; i++ ) {
        int p = prime[i];
        ll j = p * p;

        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

        for ( ; j <= b; j += p ) {
            segsieve[j - a] = 1; ///mark them as not prime
        }
    }

    int res = 0;
    for (ll i = a; i <= b; i++ ) {
        ///If it is not marked, then it is a prime
        if ( segsieve[i - a] == 0 ) res++;
    }
    return res;
}

////////////////////////// SIEVE END //////////////////////////

int main() {
    __FastIO;
    ll t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int root = (int) sqrt(50);
        int primesize = sieve(root);
        rep(i, 10) debug2(i, primelst[i]);
        segmentedSieve(10, 20, primesize);
        for (ll i = 0; i <= 10; i++) if (!segsieve[i - 10]) cout << i + 10 << '\n';
        cout << '\n';
    }
    return 0;
}
