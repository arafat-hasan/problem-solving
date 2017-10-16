/*
 * FILE: "untitled.cpp"
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * Creation Date : 28-04-2017
 * Last Modified :
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * ** *** 17    1.0         File Created
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
#define __ ios_base::sync_with_stdio(false);\
    cin.tie(0);

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define ALL(ar) ar.begin(), ar.end()
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define CLR(a) memset(a,0,sizeof a)
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
#define DEBUG(x) cout << #x <<": "<< x <<endl

#define PB push_back
#define MAX(a, b)  (a < b ? b : a)
#define MIN(a, b)  (a > b ? b : a)
#define SQ(a) a * a
#define INF 2147483646
#define MOD 1000000007

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, zl = 0, mid;
    cin >> n;
    int a[n], z[n];
    REP(i, n) {
        cin >> a[i];
        if (a[i] == 0) {
            z[zl++] = i;
        }
    }
    REP(i, z[0] + 1) cout << z[0] - i << ' ';
    REP(i, zl - 1) {
        mid = (z[i + 1] - z[i]) / 2;
        FOR(j,  z[i] + 1, z[i] + mid) {
            cout << j - z[i] << ' ';
        }
        FOR(j, z[i] + mid + 1, z[i + 1]) {
            cout << z[i + 1] - j << ' ';
        }
    }
    FOR(i, z[zl - 1] + 1, n - 1 ) cout << i - z[zl - 1] << ' ';
    ln;
    return 0;
}
