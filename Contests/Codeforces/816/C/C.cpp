/*
 * FILE: C.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 17-06-17 21:59:17 (+06)
 * LAST MODIFIED: 17-06-17 22:25:00 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 17-06-17     1.0         File Created
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
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/

int mat[101][101];
int row[101], col[101];
int main() {
    __FastIO;
    int n, m, min;
    cin >> n  >> m;
    REP(i, n) REP(j, m) cin >> mat[i][j];
    //REP(i, n) {
    //    REP(j, m) cout <<  mat[i][j] << ' ';
    //    NL;
    //}
    REP(i, n) {
        min = INF;
        REP(j, m) {
            if (min > mat[i][j]) min = mat[i][j];
        }
        if (min > 0) {
            row[i] = min;
            REP(j, m) mat[i][j] -= min;
        }
    }


    //CHK;
    //REP(i, n) {
    //    REP(j, m) cout <<  mat[i][j] << ' ';
    //    NL;
    //}

    REP(j, m) {
        min = INF;
        REP(i, n) {
            if (min > mat[i][j]) min = mat[i][j];
        }
        if (min > 0) {
            col[j] = min;
            REP(i, n) mat[i][j] -= min;
        }
    }
    int ans = 0;
    REP(i, n) ans += row[i];
    REP(i, m) ans += col[i];
    if (ans == 0) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    REP(i, n) REP(j, row[i]) cout << "row " << i + 1 << '\n';
    REP(i, m) REP(j, col[i]) cout << "col " << i + 1 << '\n';
    return 0;
}

