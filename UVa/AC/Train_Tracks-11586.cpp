/*
 * FILE: Train_Tracks-11586.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-06-17 23:33:17 (BST)
 * LAST MODIFIED: 25-06-17 00:21:13 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 24-06-17     1.0         File Created, Accepted
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

#define PB push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define sq(a) a * a
#define INF 0x7fffffff
#define MOD 1000000007
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/

int main() {
    __FastIO;
    string str;
    int t, sz, M, F;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, str);
        sz = (int) str.size();
        F = 0, M = 0;
        Rep(i, sz) {
            if (str[i] == 'F') F++;
            if (str[i] == 'M') M++;
        }
        puts((F == M && (F - 1)) ? "LOOP" : "NO LOOP");
    }
    return 0;
}

