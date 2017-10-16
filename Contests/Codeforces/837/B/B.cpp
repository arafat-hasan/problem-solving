/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03-08-17 21:48:24 (BST)
 * LAST MODIFIED: 04-08-17 02:33:58 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 03-08-17     1.0         File Created
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
    int n, m, ans = 1;
    cin >> n >> m;
    if (n % 3 != 0 and m % 3 != 0) {
        ans = 0;
    } else {
        char fl[n][m];
        Rep(i, n) Rep(j, m) cin >> fl[i][j];
        bool vertical = 0;
        for (int i = 0; i < m; i++) {
            if (fl[0][i] != fl[0][0]) {
                vertical = 1;
            }
        }
        if (vertical == 1) {
            int strip = m / 3;
            if (fl[0][0] != 'R' and fl[0][0] != 'G' and fl[0][0] != 'B') {
                ans = 0;
                goto end;
            }
            for (int j = 0; j < strip; j++) {
                for (int i = 0; i < n; i++) {
                    if (fl[i][j] != fl[0][0]) {
                        ans = 0;
                        goto end;
                    }
                }
            }

            if ((fl[0][strip] != 'R' and fl[0][strip] != 'G' and fl[0][strip] != 'B')
                    or fl[0][0] == fl[0][strip]) {
                ans = 0;
                goto end;
            }
            for (int j = strip; j < 2 * strip; j++) {
                for (int i = 0; i < n; i++) {
                    if (fl[i][j] != fl[0][strip]) {
                        ans = 0;
                        goto end;
                    }
                }
            }

            if ((fl[0][strip * 2] != 'R' and fl[0][strip * 2] != 'G'
                    and fl[0][strip * 2] != 'B') or \
                    (fl[0][0] == fl[0][strip * 2] or fl[0][strip] == fl[0][strip * 2])) {
                ans = 0;
                goto end;
            }
            for (int j = strip * 2; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    if (fl[i][j] != fl[0][strip * 2]) {
                        ans = 0;
                        goto end;
                    }
                }
            }

        } else {
            int strip = n / 3;
            if (fl[0][0] != 'R' and fl[0][0] != 'G' and fl[0][0] != 'B') {
                ans = 0;
                goto end;
            }
            for (int j = 0; j < strip; j++) {
                for (int i = 0; i < m; i++) {
                    if (fl[j][i] != fl[0][0]) {
                        ans = 0;
                        goto end;
                    }
                }
            }

            if ((fl[strip][0] != 'R' and fl[strip][0] != 'G' and fl[strip][0] != 'B')
                    or fl[0][0] == fl[strip][0]) {
                ans = 0;
                goto end;
            }
            for (int j = strip; j < strip * 2; j++) {
                for (int i = 0; i < m; i++) {
                    if (fl[j][i] != fl[strip][0]) {
                        ans = 0;
                        goto end;
                    }
                }
            }

            if ((fl[0][0] != 'R' and fl[0][0] != 'G' and fl[0][0] != 'B')\
                    or (fl[0][0] == fl[strip * 2][0] or fl[strip][0] == fl[strip * 2][0])) {
                ans = 0;
                goto end;
            }
            for (int j = strip * 2; j < n; j++) {
                for (int i = 0; i < m; i++) {
                    if (fl[j][i] != fl[strip * 2][0]) {
                        ans = 0;
                        goto end;
                    }
                }
            }
        }
    }

end:
    if (ans == 0) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}

