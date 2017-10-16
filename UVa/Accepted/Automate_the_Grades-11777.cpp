/*
 * FILE: Automate_the_Grades-11777.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-06-17 13:20:44 (BST)
 * LAST MODIFIED: 23-06-17 13:31:26 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 23-06-17     1.0         File Created, Accepted
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
    int term1, term2, fnl, attendance, t, cs = 0, total;
    int CT[3];
    char grade;
    cin >> t;
    while (t--) {

        cin >> term1 >> term2 >> fnl >> attendance >> CT[0] >> CT[1]
            >> CT[2];

        sort(CT, CT + 3);

        total = term1 + term2 + fnl + attendance + (CT[1] + CT[2]) / 2;

        if (total >= 90)
            grade = 'A';
        else if (total >= 80)
            grade = 'B';
        else if (total >= 70)
            grade = 'C';
        else if (total >= 60)
            grade = 'D';
        else
            grade = 'F';

        cout << "Case " << ++cs << ": " << grade << '\n';

    }
    return 0;
}

