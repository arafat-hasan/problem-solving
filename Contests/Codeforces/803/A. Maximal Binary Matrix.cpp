/*
 * FILE: A. Maximal Binary Matrix.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://codeforces.com/contest/803/problem/A
 *
 * Creation Date :
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
    __
    int n, k;
    cin >> n >> k;
    int arr[n][n];
    if (k > SQ(n)) {
        cout << "-1\n";
        return 0;
    }

    REP(i, n) {
        REP(j, n) {
            arr[i][j] = 0;
        }
    }

    REP(i, n) {
        FOR(j, i, n - 1) {
            if (i == j && k >= 1) {
                arr[i][i] = 1;
                k--;
            } else if (k >= 2) {
                arr[j][i] = 1;
                arr[i][j] = 1;
                k -= 2;
            } else if (k == 1) {
                arr[i + 1][i + 1] = 1;
                k--;
            } else break;
        }
    }

    REP(i, n) {
        REP(j, n) {
            cout << arr[i][j] << ' ';
        }
        ln;
    }


    return 0;
}

