/*
 * FILE: Count-the-factors-10699.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 26-06-17 14:36:53 (BST)
 * LAST MODIFIED: 26-06-17 17:15:07 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 26-06-17     1.0         File Created, Accepted
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
#include <vector>
#include <stdint.h> //uint32_t

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define For(i, a, b) for (int i=a; i<=b; i++)
#define Rof(i, b, a) for (int i=b; i>=a; i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define all(ar) ar.begin(), ar.end()
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define nl cout << '\n';
#define SP cout << ' ';
#define gc getchar
#define chk cout << "##########\n"
#define debug1(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define sq(a) a * a
#define PI acos(-1.0)

//**************** Bit Mask ***************
#define bit(n) (1 << (n)) //2^n
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << (i)))? 1 : 0)
#define bit_on(n, i) n = (n | (1 << (i))) //set ith bit ON of the integer n
#define bit_off(n, i) n = (n & ~(1 << (i))) //set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) n = (n ^ ( 1 << (i)))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) n = (n ^ ((-(x) ^ n) & (1 << (i))))

#define PB push_back
#define INF 0x7fffffff
#define MOD 1000000007
#define MAXN 32001
#define MAXS 32000000

using namespace std;


/********************* Code starts here ************************/


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

int primefactor(int n) {

    int i, j;

    if (n == 0 || primelst[n] == 0)
        return 0;

    for (i = 0, j = 0; i < maxprime; i++) {
        if (n % prime[i] == 0) {
            while (n % prime[i] == 0) {
                n /= prime[i];
            }
            j++;
        }
    }

    return j;
}


int main() {
    __FastIO;
    int n;
    bit_sieve(MAXS);
    while (cin >> n and n) {
        cout << n << " : " << primefactor(n) << '\n';
    }
    return 0;
}
