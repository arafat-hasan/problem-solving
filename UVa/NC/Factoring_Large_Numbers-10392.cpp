/*
 * FILE: Factoring_Large_Numbers-10392.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/103/10392.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    09 Apr 2017    New             1.0        
 *
 */


/*
    ___          ___           ___                       ___
   /  /\        /  /\         /__/\        ___          /__/\
  /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
 /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
 \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
    \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
     \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
     /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
    /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
    \__\/      \  \::/       \  \:\         \__\/      \  \:\
                \__\/         \__\/                     \__\/
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <set>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a

/***************____________BIT_OPERATIONS____________***************/
// #define bit(n) (1 << (n))
// //check ith bit of integer n, 0 or 1
// #define bitchk(n, i) ((n & (1 << i))? 1 : 0)
// #define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
// #define bit_off(n, i) (n & ~(1 << i))//set ith bit OFF of the intger n
// //toggle ith bit of integer n, set 0 if 1, set 1 if 0
// #define bit_toggle(n, i) (n ^ ( 1 << i))
// //set ith bit to x (x is bool, 1 or 0) of the integer n
// #define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))

#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define ln cout << '\n';
#define sp cout << ' ';
#define chk cout << "##########\n"

#define INF 2147483646
#define MAXN 32001
#define PI acos(-1.0)
#define MAXS 100000000


typedef long long ll;
typedef double lf;
using namespace std;



int prime[MAXS], maxprime; //for sieve
int fact[100][2]; //for prime factor
//100 will be replaced with max number of factors
bool primelst[MAXS]; //for sieve

int primefactor(ll n) {
    ll i, j, h;

    if (n == 0 || n == 1) return 1;
    if (!primelst[n]) return 2;
    h = (n + 1) / 2;
    for (i = 0, j = 0; i < h ; i++) {
        if ((n % prime[i]) == 0) {
            fact[j][0] = prime[i];
            fact[j][1] = 0;
            while ((n % prime[i]) == 0) {
                n /= prime[i];
                fact[j][1]++;
            }
            j++;
        }
    }
    return j;
}

void seive(int n) {
    int i, j;
    double root = sqrt(n);
    primelst[0] = primelst[1] = 1;

    for (i = 4; i < n; i += 2)  primelst[i] = 1;

    for (i = 3, j = 0; i <= root; i += 2) {
        if (!primelst[i]) {
            for (j = i * i; j < n; j += 2 * i)
                primelst[j] = 1;
        }
    }

    for (i = 0, j = 0; i < n; i++)
        if (!primelst[i])
            prime[j++] = i;

    maxprime = j - 1;
}


int main() {

    std::ios::sync_with_stdio(false);
    ll n;
    int l;
    seive(MAXS);
    while (cin >> n && n >= 0) {
        l = primefactor(n);
        REP(i, l) {
            REP(j, fact[i][1]) {
                cout << "    ";
                cout << fact[i][0] << '\n';
            }
        }
    }

    return 0;

}



