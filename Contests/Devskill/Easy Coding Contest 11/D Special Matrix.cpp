/*
 * FILE: D Special Matrix.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 13-05-17 22:53:24 (+06)
 * LAST MODIFIED: 14-05-17 01:47:06 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 13-05-17     1.0         File Created
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

int main() {
    __FastIO;
    int n, q;
    //CHK;
    cin >> n >> q;
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        //CHK;
        for (int j = 0; j < n; j++) {
            mat[i][j] = -1;
        }
    }
    map<int, pair<int, int> > mp;
    int nn = n * n;
    int x = 0, y = 0;
    //NL; NL; NL;
    //CHK;
    //int rr = 9;
    while (1) {
        //DEBUG1(nn);
        for (; y < n; y++) {
            if (mat[x][y] != -1) break;
            mat[x][y] = nn--;
            mp[mat[x][y]] = make_pair(x, y);
        }
        if (nn <= 0) break;
        x++; y--;
        for (; x < n; x++) {
            if (mat[x][y] != -1) break;
            mat[x][y] = nn--;
            mp[mat[x][y]] = make_pair(x, y);
        }
        if (nn <= 0) break;
        y--; x--;
        for (; y >= 0; y--) {
            if (mat[x][y] != -1) break;
            mat[x][y] = nn--;
            mp[mat[x][y]] = make_pair(x, y);
        }
        if (nn <= 0) break;
        x--; y++;
        for (; x >= 0; x--) {
            if (mat[x][y] != -1) break;
            mat[x][y] = nn--;
            mp[mat[x][y]] = make_pair(x, y);
        }
        if (nn <= 0) break;
        y++; x++;
    }

    //CHK;
    ////DEBUG1(mat[999][999]);
    REP(i, n) {
        REP(j, n) {
            cout << mat[i][j] << '\t';
        }
        NL;
    }
    int m;
    for (int i = 0; i < q; i++) {
        cin >> m;
        cout << mp[m].first + 1 << ", " << mp[m].second + 1 << '\n';
    }

    return 0;
}

