/*
 * FILE: 2116-The_Mobious_function.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://icpcarchive.ecs.baylor.edu/external/21/2116.pdf
 *
 * DATE CREATED: 24-10-17 18:58:26 (+06)
 * LAST MODIFIED: 02-11-17 20:04:52 (+06)
 *
 * DESCRIPTION: Number Theory, Möbius function
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-10-17     1.0         File Created, Accepted
 *
 *
 *
 *                 ██╗███████╗███╗   ██╗██╗███╗   ██╗
 *                 ██║██╔════╝████╗  ██║██║████╗  ██║
 *                 ██║█████╗  ██╔██╗ ██║██║██╔██╗ ██║
 *            ██   ██║██╔══╝  ██║╚██╗██║██║██║╚██╗██║
 *            ╚█████╔╝███████╗██║ ╚████║██║██║ ╚████║
 *             ╚════╝ ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝
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

#define forr(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005
#define MAXS            10000005

////////////////////////// START HERE //////////////////////////

bool primelst[MAXS]; //for sieve
int prime[MAXS]; //for sieve

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

int fact[1000][2]; //for prime factor
//100 will be replaced with max number of factors

int primefactor(int n) {
    // res is return value of seive
    int i, j;

    if (n == 0)
        return 0;
    if (primelst[n] == 0) {
        fact[0][0] = n;
        fact[0][1] = 1;
        return 1;
    }

    for (i = 0, j = 0; i <= n; i++) {
        if (prime[i] > n) break;
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

int mu[MAX];

void mobious_func(int n) {
    int num_of_unique_factors, fl;
    sieve(MAXS);
    for (int i = 1; i <= n; i++) {
        num_of_unique_factors = primefactor(i);
        fl = 2;
        for (int j = 0; j < num_of_unique_factors; j++) {
            if (fact[j][1] > 1) {
                fl = 0;
                break;
            }
        }
        if (fl == 0) mu[i] = 0;
        else {
            if (num_of_unique_factors & 1)
                mu[i] = -1;
            else mu[i] = 1;
        }
    }
}

int main() {
    __FastIO;
    mobious_func(10001);
    int n, fl = 0;
    while (cin >> n and n != -1) {
        if (fl++) cout << '\n';
        cout << "M(" << n << ") = " << mu[n] << '\n';
    }
    return 0;
}

