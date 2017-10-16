/*
 * FILE: B. Sagheer, the Hausmeister.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 01-06-17 20:52:49 (+06)
 * LAST MODIFIED: 03-06-17 00:24:28 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 01-06-17     1.0         File Created
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
    int n, m, fl, pos = 0,
                  lstpos, lftdis, rhtdis, lftdisup, rhtdisup,
                  cnt = 0, k, fpos, flc;
    char bld[16][105], lft = 1;
    cin >> n >> m;
    REP(i, n) REP(j, m + 2) cin >> bld[i][j];
    //REP(i, n) {
    //    REP(j, m + 2) cout <<  bld[i][j] << ' ';
    //    NL;
    //}
    //NL; NL;
    for (fl = n - 1; fl >= 0;) {
        //DEBUG1(fl);
        lstpos = 0;
        fpos = pos;
        for (; pos >= 0 && pos < m + 2;) {
            if (bld[fl][pos] == '1') {
                bld[fl][pos] = '0';
                lstpos = pos;
            }
            if (lft == 1) pos++;
            else pos--;
        }
        cnt += abs(lstpos - fpos);
        //DEBUG2(lstpos, fpos);
        //DEBUG1(cnt);
        fl--;
        if (fl >= 0) {
            lftdisup = -1; flc = fl; rhtdisup = m + 1;
            while (flc >= 0) {
                //DEBUG1(flc);
                for (k = 0; k < m + 2; k++) {
                    //DEBUG2(k, bld[flc][k]);
                    if (bld[flc][k] == '1') {
                        lftdisup = k;
                        break;
                    }
                }
                //NL;
                for (k = m + 1; k >= 0; k--) {
                    //DEBUG2(k, bld[flc][k]);
                    if (bld[flc][k] == '1') {
                        rhtdisup = k;
                        break;
                    }
                }
                //if (flc > n) break;
                if ((lftdisup < m + 2 && lftdisup >= 0)) break;
                flc--;
            }
            //DEBUG2(flc, lftdisup);
            if (lftdisup == -1) break;
            //DEBUG2(rhtdisup, lftdisup);
            lftdis = rhtdisup + lstpos + fl - flc + 1;
            //lftdis = lftdisup + lstpos + fl - flc + 1;
            rhtdis = m + 2 - lftdisup - 1  + m + 2 - lstpos - 1 + fl - flc + 1;
            //rhtdis = rhtdisup + m - lstpos + 1 + fl - flc + 1;
            //DEBUG2(rhtdis, lftdis);
            if (lftdis > rhtdis) {
                cnt += m - lstpos + 2 + fl - flc;
                lft = 0;
                pos = m + 1;
            } else {
                cnt += lstpos + 1 + fl - flc;
                lft = 1;
                pos = 0;
            }
            fl = flc;
        }
        //DEBUG1(cnt);
        //CHK;
    }
    cout << cnt << '\n';
    return 0;
}

