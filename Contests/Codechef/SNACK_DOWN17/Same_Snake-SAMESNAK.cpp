/*
 * FILE: Same_Snake-SAMESNAK.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://www.codechef.com/SNCKQL17/problems/SAMESNAK
 *
 * DATE CREATED: 20-05-17 20:50:03 (+06)
 * LAST MODIFIED: 23-05-17 14:47:01 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 20-05-17     1.0         File Created, AC
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
    int T, asx, asy, bsx, bsy, aex, aey, bex, bey, sz_a, sz_b;
    cin >> T;
    while (T--) {
        cin >> asx >> asy >> aex >> aey;
        cin >> bsx >> bsy >> bex >> bey;

        if (asx == aex) {
            sz_a = abs(asy - aey);
        } else {
            sz_a = abs(asx - aex);
        }

        if (bsx == bex) {
            sz_b = abs(bsy - bey);
        } else {
            sz_b = abs(bsx - bex);
        }
        if (sz_a < sz_b) {
            swap(asx, bsx);
            swap(asy, bsy);
            swap(aex, bex);
            swap(aey, bey);
        }


        if (asx != aex) {
            swap(asy, asx);
            swap(aey, aex);
            swap(bsy, bsx);
            swap(bey, bex);
        }

        if (asy > aey) {
            swap(asy, aey);
            swap(asx, aex);
        }

        if (bsx == bex) {
            if (bsy > bey) {
                swap(bsy, bey);
                swap(bsx, bex);
            }
            if ( (asx == bsx) && ((bey >= asy && bey <= aey) || (bsy >= asy
                                  && bsy <= aey))) {
                cout << "yes\n" ;
            } else {
                cout << "no\n";
            }

        } else {

            if (bsx > bex) {
                swap(bsx, bex);
                swap(bsy, bey);
            }

            if (asx == bsx && asy == bsy) cout << "yes\n";
            else if (asx == bex && asy == bey) cout << "yes\n";
            else if (aex == bex && aey == bey) cout << "yes\n";
            else if (aex == bsx && aey == bsy) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}

