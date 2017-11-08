/*
 * FILE: GCDEX.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 05-11-17 19:15:07 (+06)
 * LAST MODIFIED: 06-11-17 00:16:51 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 05-11-17     1.0         {{File Created}}
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
#define MAX             1000005

////////////////////////// START HERE //////////////////////////

// phi[i] stores euler totient function for i
// gcdsum[j] stores result for value j
ll phi[MAX];
ll gcdsum[MAX];

class Totient {

public:

/// Computes and prints totien of all numbers
/// smaller than or equal to n.
/// http://www.geeksforgeeks.org/
/// eulers-totient-function-for-all-numbers-smaller-than-or-equal-to-n/
    void compute(int n) {
        // Create and initialize an array to store
        // phi or totient values
        //long long phi[n + 1];
        for (int i = 1; i <= n; i++)
            phi[i] = i; // indicates not evaluated yet
        // and initializes for product
        // formula.

        // Compute other Phi values
        for (int p = 2; p <= n; p++) {
            //If phi[p] is not computed already,
            //then number p is prime

            if (phi[p] == p) {
                // Phi of a prime number p is
                // always equal to p-1.
                phi[p] = p - 1;

                // update phi values of all
                // multiples of p
                for (int i = 2 * p; i <= n; i += p) {
                    // Add contribution of p to its
                    // multiple i by multiplying with
                    // (1 - 1/p)
                    phi[i] = (phi[i] / p) * (p - 1);
                }
            }
        }
    }

//Precomputes result for all numbers till MAX
    void sumOfGcdPairs(int n) {
        // Precompute all phi value
        compute(n);

        //gcdsum[0] = 0;
        for (int i = 1; i < n; ++i) {
            // Iterate throght all the divisors
            // of i.
            for (int j = 2; i * j < n; ++j)
                gcdsum[i * j] += i * phi[j];
        }

        // Add summation of previous calculated sum
        for (int i = 2; i < n; i++)
            gcdsum[i] += gcdsum[i - 1];
    }

// http://www.geeksforgeeks.org/eulers-totient-function/
    int phi_single(int n) {
        int res = n;   // Initialize result as n

        // Consider all prime factors of n and subtract their
        // multiples from result
        for (int p = 2; p * p <= n; ++p) {
            // Check if p is a prime factor.
            if (n % p == 0) {
                // If yes, then update n and result
                while (n % p == 0)
                    n /= p;
                res -= res / p;
            }
        }

        // If n has a prime factor greater than sqrt(n)
        // (There can be at-most one such prime factor)
        if (n > 1)
            res -= res / n;
        return res;
    }
};

int main() {
    //__FastIO;
    int n;
    Totient totient;
    totient.compute(MAX);
    totient.sumOfGcdPairs(MAX);
    while (cin >> n and n) {
        cout << gcdsum[n] << '\n';
    }
    return 0;
}

