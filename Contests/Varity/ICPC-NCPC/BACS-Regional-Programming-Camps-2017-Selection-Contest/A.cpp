/*
 * FILE: A.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 07-07-17 15:00:55 (BST)
 * LAST MODIFIED: 07-07-17 16:18:25 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 07-07-17     1.0         File Created
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

#define For(i, a, b) for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a) for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n) for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
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
    int t, n, tmp, sz, max;
    vector<int> v, ans, u;
    bool fl;
    cin >> t;
    while (t--) {
        cin >> n;
        //debug2(t, n);
        v.clear();
        u.clear();
        ans.clear();
        Rep(i, n) {
            cin >> tmp;
            v.push_back(tmp);
            u.push_back(tmp);
        }
        sort(u.begin(), u.end());
        fl = 1;
        Rep(i, n) {
            if (v[i] != u[i]) {
                fl = 0;
                break;
            }
        }
        if (fl) {
            if (v[0] == v[n - 1])cout << "neutral\n";
            else cout << "allGoodDays\n";
            continue;
        }
        reverse(u.begin(), u.end());
        fl  = 1;
        Rep(i, n) {
            //debug2(v[i], u[i]);
            if (v[i] != u[i]) {
                fl = 0;
                break;
            }
        }

        if (fl) {
            cout << "allBadDays\n";
            continue;
        }

        For(i, 1,  n - 2) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
                ans.push_back(i);
            }
        }
        sz = (int) ans.size();
        if (sz <= 1) {
            cout << "none\n";
            continue;
        }
        max = -INF;
        For(i, 1, sz - 1) {
            if (ans[i] - ans[i - 1] > max) max = ans[i] - ans[i - 1];
        }
        cout << max - 1 << '\n';
    }
    return 0;
}

