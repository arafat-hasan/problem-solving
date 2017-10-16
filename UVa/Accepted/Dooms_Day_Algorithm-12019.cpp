/*
 * FILE: Dooms_Day_Algorithm-12019.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 15-07-17 17:28:40 (BST)
 * LAST MODIFIED: 15-07-17 22:45:06 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 15-07-17     1.0         File Created, Accepted
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

enum week {Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday};
const char *dayNames[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main() {
    __FastIO;
    int t, m, d, diff, ans;
    enum week doomsday = Monday;
    cin >> t;
    while (t--) {
        cin >> m >> d;
        int feb_len = 28, feb_dooms_date = 21;
        int doomsdate = m;
        if (m == 2) doomsdate = 21;
        else if (m == 1) doomsdate = 10;
        //if (is_leapyer(y)) {
        //    feb_len++;
        //    feb_doomsdate = 22;
        //    if (m == 1 or m == 2) doomsdate++;
        //}
        if (m == 3 or m == 5 or m == 7 or m == 9 or m == 11) {
            int pre_mth_doomsdate = m - 1, month_len = 30;
            if (m == 3) pre_mth_doomsdate = feb_dooms_date;
            if (m == 9 or m == 11 ) month_len = 31;
            else if (m == 3) month_len = feb_len;
            diff = ( month_len - pre_mth_doomsdate  ) / 7;
            diff++;
            diff = diff * 7;
            doomsdate = diff - (month_len - pre_mth_doomsdate);
        }
        diff = abs( d - doomsdate ) % 7;
        ans = ( d > doomsdate ? diff + doomsday : doomsday - diff );
        if (ans < 0 ) ans += 7;
        else if ( ans > 6 ) ans -= 7;
        cout << dayNames[ans] << '\n';
    }
    return 0;
}

