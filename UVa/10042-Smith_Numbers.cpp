/*
 * FILE: Smith_Numbers-10042.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 13-05-17 20:32:39 (+06)
 * LAST MODIFIED: 05-07-17 13:40:02 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 13-05-17     1.0         File Created, Accepted
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

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define ALL(ar) ar.begin(), ar.end()
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define NL cout << '\n';
#define SP cout << ' ';
#define CHK cout << "##########\n"
#define DEBUG1(x) cout << #x << ": " << x << endl
#define DEBUG2(x, y) cout << #x << ": " << x << "\t" << #y << ": " << y << endl
#define DEBUG3(x, y, z) cout << #x << ": " << x << "\t" << #y << ": " << y << "\t" << #z << ": " << z << endl

#define PB push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646
#define MOD 1000000007
#define MAXN 32001
#define PI acos(-1.0)
#define MAXS 10000000

using namespace std;

/********************* Code starts here ************************/


int prime[MAXS], maxprime; //for sieve
int fact[500][2]; //for prime factor
//100 will be replaced with max number of factors
bool primelst[MAXS]; //for sieve


void sieve(int n) {

    int i, j;
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
    for (i = 0, j = 0; i < n; i++) {

        if (primelst[i] == 0) {
            prime[j++] = i;
        }
    }

    maxprime = j - 1;
}


int primefactor(int n) {

    int i, j = 0, h = n / 2 + 1;
    int tmp = n;
    if (n < 4) return 0;
    for (i = 0, j = 0; prime[i] <= h and n > 1 and i <= maxprime; i++) {
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

    if (n != 1 and n != tmp) {
        fact[j][0] = n;
        fact[j][1] = 1;
        j++;
    }
    return j;
}


int sumofdigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sumofprimefactors(int n) {
    int j = primefactor(n), sum = 0;
    REP(i, j) {
        REP(k, fact[i][1]) {
            sum += sumofdigits(fact[i][0]);
        }
    }
    return sum;
}


int main() {
    __FastIO;
    sieve(MAXS);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        while (1) {
            n++;
            if (sumofdigits(n) == sumofprimefactors(n)) {
                cout << n << '\n';
                break;
            }

        }
    }

    return 0;
}

