/*
 * FILE: Power_Crisis-151.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 22-07-17 02:36:22 (BST)
 * LAST MODIFIED: 22-07-17 06:06:30 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 22-07-17     1.0         File Created, Accepted, Accepted
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
#define clr(a)          memset(a, 0, sizeof(a))

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
    int n;
    bool fl;
    vi v;
    while (cin >> n and n) {
        For(j, 1, 100) {
            For(i, 1, n) v.pb(i);
            int m = n;
            fl = 0;
            for (int i = 0; m; i += j) {
                if (i >= m) i %= m;
                if (m == 1 and v[0] == 13) {
                    fl = 1;
                    break;
                }
                if (m == 1) break;
                v.erase(v.begin() + i);
                m--;
                i--;
            }
            v.clear();
            if (fl) {
                cout << j << '\n';
                break;
            }
        }
    }
    return 0;
}


// 0.00s, AC
//int main() {
//    __FastIO;
//    int n, arr[105], last;
//    bool fl;
//    while (cin >> n and n) {
//        for (int i = 1; i <= 300; i++) {
//            clr(arr);
//            for (int j = 1; ;) {
//                arr[j] = 1;
//                last = j;
//                fl = 1;
//                for (int k = 1; k <= n; k++) {
//                    if (arr[k] == 0) {
//                        fl = 0;
//                        break;
//                    }
//                }
//                if (fl == 1) break;
//                int m = 0;
//                while (1) {
//                    j++;
//                    if (j > n) j -= n;
//                    if (arr[j] == 0) m++;
//                    if (m == i) break;
//                }
//            }
//            if (last == 13) {
//                cout << i << '\n';
//                break;
//            }
//        }
//    }
//    return 0;
//}

