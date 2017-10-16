/*
 * FILE: Charging_the_Batteries.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 07-08-17 22:14:41 (BST)
 * LAST MODIFIED: 08-08-17 00:33:35 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 07-08-17     1.0         File Created
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

#define FileIn(file)    freopen("input.txt", "r", stdin)
#define FileOut(file)   freopen("output.txt", "w", stdout)
#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

#define sfll(a)         scanf("%lld", &a)
#define pfll(a)         printf("%lld", a)
#define sflf(a)         scanf("%lf", &a)
#define pflf(a)         printf("%lf", a)
#define sff(a)          scanf("%f", &a)
#define pff(a)          printf("%f", a)
#define sf(a)           scanf("%d", &a)
#define pf(a)           printf("%d", a)

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
#define MAXN            32001
#define MAXS            100000000
#define MAX             10000005


////////////////////////// START HERE //////////////////////////

//int st, bk;
int sliding_window(vector<int> v, int k) {
    int sz = (int) v.size(), minsum = INF, sum = 0, back, init = 0;
    for (int j = 0; j < k ; init++, j++) {
        if (init == sz) init = 0;
        sum += v[init];
    }
    bool fl = 0;
    for (int i = init;; i++) {
        if (i == sz) i = 0;
        if (i == k and fl == 1) break;
        fl = 1;
        back = i - k;
        if (back < 0) back += sz;
        sum += v[i];
        sum -= v[back];
        if (sum < minsum) {
            //st = i;
            //bk = back;
            minsum = sum;
        }
    }
    return minsum;
}

int main() {
    __FastIO;
    int n, m, k, tmp1, tmp2;
    cin >> n >> m >> k;
    vector<int> bot, right, top, left, v;
    Rep(j, m) {
        cin >> tmp1 >> tmp2;

        //debug2(tmp1, tmp2);
        if (tmp2 == 0) { // bottom
            //cout << "1\n";
            bot.pb(tmp1);
        } else if (tmp1 == n) { // right
            //cout << "2\n";
            right.pb(tmp2);
        } else if (tmp2 == n) { // top
            //cout << "3\n";
            top.pb(tmp1);
        } else if (tmp1 == 0) { // left
            //cout << "4\n";
            left.pb(tmp2);
        }

    }

    sort(all(bot));
    sort(all(right));
    sort(all(top));
    reverse(all(top));
    sort(all(left));
    reverse(all(left));

    for (int i = 1; i < (int) bot.size(); i++) {
        v.pb(bot[i] - bot[i - 1]);
    }
    v.pb(n - bot[(int) bot.size() - 1] + right[0]);
    for (int i = 1; i < (int) right.size(); i++) {
        v.pb(right[i] - right[i - 1]);
    }
    v.pb(n - right[(int) right.size() - 1] + (n - top[0]));
    for (int i = 1; i < (int) top.size(); i++) {
        v.pb(top[i - 1] - top[i]);
    }
    v.pb(top[(int) top.size() - 1] + (n - left[0]));
    for (int i = 1; i < (int) left.size(); i++) {
        v.pb(left[i - 1] - left[i]);
    }
    v.pb(left[(int) left.size() - 1] + bot[0]);

    //for (int i = 0; i < (int) bot.size(); i++)
    //    cout << bot[i] << ' ' ;
    //nl;
    //for (int i = 0; i < (int) right.size(); i++)
    //    cout << right[i] << ' ' ;
    //nl;
    //for (int i = 0; i < (int) top.size(); i++)
    //    cout << top[i] << ' ' ;
    //nl;
    //for (int i = 0; i < (int) left.size(); i++)
    //    cout << left[i] << ' ' ;
    //nl;

    //for (int i = 0; i < (int) v.size(); i++)
    //    cout << v[i] << ' ' ;
    //nl;

    int minsum = sliding_window(v, k - 1);
    //debug2(st, bk);
    cout << minsum << '\n';
    return 0;
}

