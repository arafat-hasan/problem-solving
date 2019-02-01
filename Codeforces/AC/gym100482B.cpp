/*
 * FILE: gym100482B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://codeforces.com/gym/100482/problem/B
 *
 * DATE CREATED: 01-08-17 00:45:24 (BST)
 * LAST MODIFIED: 01-08-17 00:45:51 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 01-08-17     1.0         File Created
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

/////////////////////////////////////////////////////////////////////////////

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
#include <deque>
#include <vector>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cout << #x << ": " << x << endl
#define debug2(x, y)    cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-10
#define MAX             10000005

////////////////////////// START HERE //////////////////////////


int main() {
    __FastIO;
    int t, x[4], y[4], cs = 0;
    lf price;
    cin >> t;
    cout << fixed << setprecision(2);
    while (t--) {
        Rep(i, 4) cin >> x[i] >> y[i];
        cin >> price;
        lf a = sqrt(sq((x[0] - x[1])) + sq((y[0] - y[1])));
        lf b = sqrt(sq((x[1] - x[2])) + sq((y[1] - y[2])));
        lf c = sqrt(sq((x[2] - x[3])) + sq((y[2] - y[3])));
        lf d = sqrt(sq((x[3] - x[0])) + sq((y[3] - y[0])));
        lf m1 = sqrt(sq((x[0] - x[2])) + sq((y[0] - y[2])));
        lf m2 = sqrt(sq((x[1] - x[3])) + sq((y[1] - y[3])));

        lf s = (a + b + m1) / 2.0;
        lf tri1 = sqrt(s * (s - a) * (s - b) * (s - m1));
        s = (c + d + m1) / 2.0;
        lf tri2 = sqrt(s * (s - c) * (s - d) * (s - m1));

        lf qdr1 = tri1 + tri2;

        s = (d + a + m2) / 2.0;
        tri1 = sqrt(s * (s - d) * (s - a) * (s - m2));
        s = (b + c + m2) / 2.0;
        tri2 = sqrt(s * (s - b) * (s - c) * (s - m2));

        lf qdr2 = tri1 + tri2;

        lf qdr = min(qdr1, qdr2);

        lf ans = price / qdr;
        cout << "Case #" << ++cs << ": " << ans << '\n';

    }
    return 0;
}
